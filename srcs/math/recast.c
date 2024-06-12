/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:24:06 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/07 11:33:23 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D.h"
#include "calcul.h"


void	ft_drawLine(int x, int *draw, unsigned int color, t_data *data)
{
	int	i;

	i = 0;
	while (i < draw[0])
	{
		my_mlx_pixel_put(data, x, i, data->map->c.rgb);
		i++;
	}
	while (draw[0] < draw[1])
	{
		my_mlx_pixel_put(data, x, draw[0], color);
		draw[0]++;
	}
	while (draw[1] < HEIGHT)
	{
		my_mlx_pixel_put(data, x, draw[1], data->map->f.rgb);
		draw[1]++;
	}	
}

void 	recast(t_data *data)
{
	double	pos_x;
	double	pos_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		x;

	x = 0;
	pos_x = data->map->player->pos.x;
	pos_y = data->map->player->pos.y;
	while (x < WIDTH)
	{
		ray_dir_x = data->map->player->dir.x
			+ data->map->player->plane.x * (2 * x / (double)WIDTH - 1);
		ray_dir_y = data->map->player->dir.y
			+ data->map->player->plane.y * (2 * x / (double)WIDTH - 1);
		map_x = (int)pos_x;
		map_y = (int)pos_y;
		double side_dist_x;
		double side_dist_y;

		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = 0;
		double deltaDistY = 0;
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		deltaDistX = (!ray_dir_x) * 1e30 + (ray_dir_x)
			* sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
		deltaDistY = (!ray_dir_y) * 1e30 + (ray_dir_y)
			* sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));
		if(ray_dir_x < 0)
		{
			stepX = -1;
			side_dist_x = (pos_x - map_x) * deltaDistX;
		}
		else
		{
			stepX = 1;
			side_dist_x = (map_x + 1.0 - pos_x) * deltaDistX;
		}
		if(ray_dir_y < 0)
		{
			stepY = -1;
			side_dist_y = (pos_y - map_y) * deltaDistY;
		}
		else
		{
			stepY = 1;
			side_dist_y = (map_y + 1.0 - pos_y) * deltaDistY;
		}
			//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(side_dist_x < side_dist_y)
			{
				side_dist_x += deltaDistX;
				map_x += stepX;
				side = 0;
			}
			else
			{
				side_dist_y += deltaDistY;
				map_y += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(data->map->map[map_x][map_y] == '1')
				hit = 1;
		}
		if(side == 0)
			perpWallDist = (side_dist_x - deltaDistX);
		else
			perpWallDist = (side_dist_y - deltaDistY);
		//Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

		//choose wall color
		unsigned int color;
		color = GREEN;
		//give x and y sides different brightness
		if(side == 1) {color = color / 2;}
		//draw the pixels of the stripe as a vertical line
		int draw[2];
		draw[0] = drawStart;
		draw[1] = drawEnd;
		ft_drawLine(x, draw, color, data);
		x++;
	}
	display_minimap(data->map, data);
	mlx_put_image_to_window(data->g->mlx, data->g->win, data->g->img->img, 0, 0);
}
