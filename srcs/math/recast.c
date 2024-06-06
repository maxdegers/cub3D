/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:24:06 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/06 14:20:46 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D.h"
#include "calcul.h"


void	ft_drawLine(int x, int drawStart, int drawEnd, unsigned int color, t_data *data)
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

void 	recast(t_data *data)
{
	double posX, posY ;  //x and y start position
  	double dirX = -1, dirY = 0; //initial direction vector
  	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

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
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h) drawEnd = h - 1;

		//choose wall color
		unsigned int color;
		color = GREEN;
		//give x and y sides different brightness
		if(side == 1) {color = color / 2;}
		//draw the pixels of the stripe as a vertical line
		ft_drawLine(x, drawStart, drawEnd, color, data);
		x++;
	}
	display_minimap(data->map, data);
	mlx_put_image_to_window(data->g->mlx, data->g->win, data->g->img->img, 0, 0);
}
