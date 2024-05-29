/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:08:10 by gberthol          #+#    #+#             */
/*   Updated: 2024/05/29 12:08:10 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "calcul.h"

void	mlx_draw_line(t_data *data, int draw_start, int draw_stop, int x)
{
	while (draw_start < draw_stop)
	{
		mlx_pixel_put(data->g->mlx, data->g->win, x,
			draw_start, data->map->c->rgb);
		draw_start++;
	}
}

void	draw_columns(t_map *map, t_data *data, t_ray *ray)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(HEIGHT / ray->perm_wall_dist);
	draw_start = -lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	draw_end = lineHeight / 2 + HEIGHT / 2;
	if (drawEnd >= HEIGHT)
		drawEnd = HEIGHT - 1;
	mlx_draw_line(data, draw_start, draw_end, x);
}

void	find_wall(t_map *map, t_data *data, t_ray *ray)
{
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
		if (map->map[map_pos.y][map_pos.x] > 0)
			ray->hit = 1;
		if (!ray->side)
			ray->perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
		else
			ray->perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	}
	draw_colum(map, data, ray);
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
		ray->side_dist.y = (map_pos.y + 1.0 - map->player->pos.y)
			* ray->delta_dist.y;
	}
}

void	calc_dist(t_map *map, t_data *data, t_ray *ray)
{
	ray->side_dist.x = 0;
	ray->side_dist.y = 0;
	ray->delta_dist.x = !(ray_dir->x) * 2147483647;
	if (ray->dir.x)
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = !(ray->dir.y) * 2147483647;
	if (ray->dir.y)
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

void	display_column(t_map *map, t_data *data)
{
	unsigned int	x;
	double			camera_x;
	t_ray			ray;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		ray.dir.x = map->player->dir->x + map->player->plane->x * camera_x;
		ray.dir.y = map->player->dir->y + map->player->plane->y * camera_x;
		ray.pos.x = (int)map->player->pos->x;
		ray.pos.y = (int)map->player->pos->y;
		calc_dist(map, data, &ray);
		x++;
	}
}
