/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 13:50:23 by gberthol          #+#    #+#             */
/*   Updated: 2024/05/28 13:50:23 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "calcul.h"

void mlx_draw_line(t_data *data, int draw_start, int draw_stop, int x)
{
	while (draw_start < draw_stop)
	{
		mlx_pixel_put( data->g->mlx, data->g->win, x, draw_start, data->map->c->rgb);
		draw_start++;
	}
}

void	display_column(t_map *map, t_data *data)
{
	unsigned int	x;
	double			camera_x;
	t_vector		ray_dir;
	t_vector		side_dist;
	t_vector		delta_dist;
	t_vector_i		map_pos;
	double			perm_wall_dist;
	t_vector_i		step;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;

	x = 0;
	hit = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		ray_dir.x = map->player->dir->x + map->player->plane->x * camera_x;
		ray_dir.y = map->player->dir->y + map->player->plane->y * camera_x;
		map_pos.x = (int)map->player->pos->x;
		map_pos.y = (int)map->player->pos->y;
		side_dist.x = 0;
		side_dist.y = 0;
		if (ray_dir.x)
			delta_dist.x = fabs(1 / ray_dir.x);
		else
			delta_dist.x = 2147483647;
		if (ray_dir.y)
			delta_dist.y = fabs(1 / ray_dir.y);
		else
			delta_dist.y = 2147483647;
		if (ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (map->player->pos->x - map_pos.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (map_pos.x + 1.0 - map->player->pos->x) * delta_dist.x;
		}
		if (ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (map->player->pos->y - map_pos.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (map_pos.y + 1.0 - map->player->pos->y) * delta_dist.y;
		}
		while (hit == 0)
		{
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				map_pos.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist.y;
				map_pos.y += step.y;
				side = 1;
			}
			if (map->map[map_pos.y][map_pos.x] > 0)
				hit = 1;
			if (side == 0)
				perp_wall_dist = (side_dist.x - delta_dist.x);
			else
				perp_wall_dist = (side_dist.y - delta_dist.y);
		}
		line_height = (int)(HEIGHT / perm_wall_dist);
		draw_start = -lineHeight / 2 + HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		draw_end = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT)
			drawEnd = HEIGHT - 1;
		mlx_draw_line(data, draw_start, draw_end, x);
		x++;
	}
}