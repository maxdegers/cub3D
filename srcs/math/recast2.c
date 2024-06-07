/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recast2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:24:06 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/07 20:02:33 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D.h"
#include "calcul.h"

#define TEX_WIDTH 64
#define TEX_HEIGHT 64

void	ft_drawline(int x, int drawStart, int drawEnd, unsigned int color, t_data *data)
{
	int	i;

	i = 0;
	while (i < drawStart)
	{
		my_mlx_pixel_put(data, x, i, data->map->c.rgb);
		i++;
	}
	while (drawStart < drawEnd)
	{
		my_mlx_pixel_put(data, x, drawStart, color);
		drawStart++;
	}
	while (drawEnd < HEIGHT)
	{
		my_mlx_pixel_put(data, x, drawEnd, data->map->f.rgb);
		drawEnd++;
	}	
}

void	draw_buffer(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			my_mlx_pixel_put(data, x, y, data->buf[x][y]);
			y++;
		}
		x++;
	}
}

void	clear_buf(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			data->buf[x][y] = 0;
			y++;
		}
		x++;
	}
}


void 	recast2(t_data *data)
{
	double posX, posY ;  //x and y start position
  	double dirX, dirY; //initial direction vector
  	double planeX, planeY; //the 2d raycaster version of camera plane

	int	x = 0;
	int w = WIDTH;
	int h = HEIGHT;
	char **worldMap = data->map->map;
	posX = data->map->player->pos.x;
	posY = data->map->player->pos.y;
	dirX = data->map->player->dir.x;
	dirY = data->map->player->dir.y;
	planeX = data->map->player->plane.x;
	planeY = data->map->player->plane.y;

	while (x < w)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;
			//which box of the map we're in
		int mapX = (int)posX;
		int mapY = (int)posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
			//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(worldMap[mapX][mapY] == '1')
				hit = 1;
		}
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = (-lineHeight * 0.5) + (h * 0.5);
		if(drawStart < 0) drawStart = 0;
		int drawEnd = (lineHeight * 0.5) + (h * 0.5);
		if(drawEnd >= h) drawEnd = h - 1;


		int	texNum = 0; //1 subtracted from it so that texture 0 can be used!
		double wallX; //where exactly the wall was hit
		if(side == 0) wallX = posY + perpWallDist * rayDirY;
		else          wallX = posX + perpWallDist * rayDirX;
		wallX -= floor((wallX));
		//x coordinate on the texture
		int	texX = (int)(wallX * (double)TEX_WIDTH);
		if (side == 0 && rayDirX > 0) texX = TEX_WIDTH - texX - 1;
		if (side == 1 && rayDirY < 0) texX = TEX_WIDTH - texX - 1;
		double step = (double)TEX_HEIGHT / lineHeight;
		double texPos = step * (drawStart - (h * 0.5) + (lineHeight * 0.5));
		int y = drawStart;
		uint32_t color;
		while (y < drawEnd)
		{
			int texY = (int)texPos & (TEX_HEIGHT - 1);
			texPos += step;
			color = data->tex[texNum].data[TEX_WIDTH * texY + texX];
			data->buf[x][y] = color;
			y++;
		}
		x++;
	}
	draw_buffer(data);
	clear_buf(data);
	display_minimap(data->map, data);
	mlx_put_image_to_window(data->g->mlx, data->g->win, data->g->img->img, 0, 0);
}
