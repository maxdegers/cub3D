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

void	calc_dda(t_data *data, t_ray *ray, int map_x, int map_y)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			map_x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			map_y += ray->step.y;
			ray->side = 1;
		}
		if (data->map->map[map_x][map_y] == '1')
			ray->hit = 1;
	}
}

void	calc_side_dist(t_ray *ray, t_data *data, int map_x, int map_y)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (data->map->player->pos.x - map_x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (map_x + 1.0 - data->map->player->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (data->map->player->pos.y - map_y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (map_y + 1.0 - data->map->player->pos.y)
			* ray->delta_dist.y;
	}
}

void	calc_line_height(t_ray *ray)
{
	if (ray->side == 0)
		ray->perm_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->perm_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
	ray->line_height = (int)(HEIGHT / ray->perm_wall_dist);
}

void	recast2(t_data *data)
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
		calc_side_dist(&ray, data, map_x, map_y);
		calc_dda(data, &ray, map_x, map_y);
		calc_line_height(&ray);
		draw_wall(data, &ray, x);
		x++;
	}
	display_minimap(data->map, data);
	mlx_put_image_to_window(data->g->mlx,
		data->g->win, data->g->img->img, 0, 0);
}
