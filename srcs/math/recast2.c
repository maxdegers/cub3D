/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recast2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:24:06 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/12 15:43:54 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D.h"
#include "calcul.h"

void	ft_drawline(int x, int *draw, unsigned int color, t_data *data)
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

void 	recast2(t_data *data)
{
	int		x;
	t_ray	ray;
	int		map_x;
	int		map_y;
	
	x = 0;
	while (x < WIDTH)
	{
		ray.dir.x = data->map->player->dir.x
			+ data->map->player->plane.x * (2 * x / (double)WIDTH - 1);
		ray.dir.y = data->map->player->dir.y
			+ data->map->player->plane.y * (2 * x / (double)WIDTH - 1);
		map_x = (int)data->map->player->pos.x;
		map_y = (int)data->map->player->pos.y;
		ray.hit = 0;
		calc_delta_dist(&ray);
		if (ray.dir.x < 0)
		{
			ray.step.x = -1;
			ray.side_dist.x = (data->map->player->pos.x - map_x) * ray.delta_dist.x;
		}
		else
		{
			ray.step.x = 1;
			ray.side_dist.x = (map_x + 1.0 - data->map->player->pos.x) * ray.delta_dist.x;
		}
		if (ray.dir.y < 0)
		{
			ray.step.y = -1;
			ray.side_dist.y = (data->map->player->pos.y - map_y) * ray.delta_dist.y;
		}
		else
		{
			ray.step.y = 1;
			ray.side_dist.y = (map_y + 1.0 - data->map->player->pos.y) * ray.delta_dist.y;
		}
			//perform DDA
		while(ray.hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(ray.side_dist.x < ray.side_dist.y)
			{
				ray.side_dist.x += ray.delta_dist.x;
				map_x += ray.step.x;
				ray.side = 0;
			}
			else
			{
				ray.side_dist.y += ray.delta_dist.y;
				map_y += ray.step.y;
				ray.side = 1;
			}
			//Check if ray has ray.hit a wall
			if(data->map->map[map_x][map_y] == '1')
				ray.hit = 1;
		}
		if (ray.side == 0)
			ray.perm_wall_dist = (ray.side_dist.x - ray.delta_dist.x);
		else
			ray.perm_wall_dist = (ray.side_dist.y - ray.delta_dist.y);
		//Calculate height of line to draw on screen
		int lineHeight = (int)(HEIGHT / ray.perm_wall_dist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = (-lineHeight * 0.5) + (HEIGHT * 0.5);
		if (drawStart < 0) drawStart = 0;
		int drawEnd = (lineHeight * 0.5) + (HEIGHT * 0.5);
		if (drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;
		
		int	texNum; //1 subtracted from it so that texture 0 can be used!
		if (ray.side == 0)
		{
			if (ray.step.x > 0)
				texNum = 0;
			else
				texNum = 1;
		}
		else
		{
			if (ray.step.y > 0)
				texNum = 2;
			else
				texNum = 3;
		}
		double wallX; //where exactly the wall was ray.hit
		if (ray.side == 0) wallX = data->map->player->pos.y + ray.perm_wall_dist * ray.dir.y;
		else          wallX = data->map->player->pos.x + ray.perm_wall_dist * ray.dir.x;
		wallX -= floor((wallX));
		//x coordinate on the texture
		int	texX = (int)(wallX * (double)TEX_WIDTH);
		if (ray.side == 0 && ray.dir.x > 0) texX = TEX_WIDTH - texX - 1;
		if (ray.side == 1 && ray.dir.y < 0) texX = TEX_WIDTH - texX - 1;
		double step = (double)TEX_HEIGHT / lineHeight;
		double texPos = step * (drawStart - (HEIGHT * 0.5) + (lineHeight * 0.5));
		int y = drawStart;
		uint32_t color;
		int i = 0;
		while (i < y)
		{
			my_mlx_pixel_put(data, x, i, data->map->c.rgb);
			i++;
		}
		while (y < drawEnd)
		{
			int texY = (int)texPos & (TEX_HEIGHT - 1);
			texPos += step;
			color = data->tex[texNum].data[TEX_WIDTH * texY + texX];
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		while (y < HEIGHT)
		{
			my_mlx_pixel_put(data, x, y, data->map->f.rgb);
			y++;
		}
		x++;
	}
	display_minimap(data->map, data);
	mlx_put_image_to_window(data->g->mlx, data->g->win, data->g->img->img, 0, 0);
}
