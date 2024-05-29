/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:08:10 by gberthol          #+#    #+#             */
/*   Updated: 2024/05/29 14:24:35 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "calcul.h"

void	mlx_draw_line(t_data *data, int draw_start, int draw_stop, int x)
{
	while (draw_start < draw_stop)
	{
		mlx_pixel_put(data->g->mlx, data->g->win, x,
			draw_start, data->map->c.rgb);
		draw_start++;
	}
}

void	draw_columns(t_map *map, t_data *data, t_ray *ray)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	(void)map;
	line_height = (int)(HEIGHT / ray->perm_wall_dist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	mlx_draw_line(data, draw_start, draw_end, ray->x);
}

void	find_wall(t_map *map, t_data *data, t_ray *ray)
{
	ray->perm_wall_dist = 5;
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->pos.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->pos.y += ray->step.y;
			ray->side = 1;
		}
		if (map->map[ray->pos.y][ray->pos.x] > 0)
			ray->hit = 1;
		if (!ray->side)
			ray->perm_wall_dist = ray->side_dist.x - ray->delta_dist.x;
		else
			ray->perm_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	}
	draw_columns(map, data, ray);
}

void	calc_step(t_map *map, t_data *data, t_ray *ray)
{
	ray->step.x = (ray->dir.x >= 0) - (ray->dir.x < 0);
	if (ray->dir.x < 0)
	{
		ray->side_dist.x = (map->player->pos.x - ray->pos.x)
			* ray->delta_dist.x;
	}
	else
	{
		ray->side_dist.x = (ray->pos.x + 1.0 - map->player->pos.x)
			* ray->delta_dist.x;
	}
	ray->step.y = (ray->dir.y >= 0) - (ray->dir.y < 0);
	if (ray->dir.y < 0)
	{
		ray->side_dist.y = (map->player->pos.y - ray->pos.y)
			* ray->delta_dist.y;
	}
	else
	{
		ray->side_dist.y = (ray->pos.y + 1.0 - map->player->pos.y)
			* ray->delta_dist.y;
	}
	find_wall(map, data, ray);
}

void	calc_dist(t_map *map, t_data *data, t_ray *ray)
{
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
	ray->delta_dist.x = !(ray->dir.x) * 2147483647;
	if (ray->dir.x)
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = !(ray->dir.y) * 2147483647;
	if (ray->dir.y)
		ray->delta_dist.y = fabs(1 / ray->dir.y);
	calc_step(map, data, ray);
}

void	display_column(t_map *map, t_data *data)
{
	double			camera_x;
	t_ray			ray;

	ray.x = 0;
	while (ray.x < WIDTH)
	{
		camera_x = 2 * ray.x / (double)WIDTH - 1;
		ray.dir.x = map->player->dir.x + map->player->plane.x * camera_x;
		ray.dir.y = map->player->dir.y + map->player->plane.y * camera_x;
		ray.pos.x = (int)map->player->pos.x;
		ray.pos.y = (int)map->player->pos.y;
		calc_dist(map, data, &ray);
		ray.x++;
	}
}
