/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:53:20 by gberthol          #+#    #+#             */
/*   Updated: 2024/05/29 15:53:20 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3D.h"
#define rotSpeed 0.05

void	turn_player(t_data *data, int dir)
{
	double	old_dir;
	double	old_plane;

	old_dir = data->map->player->dir.x;
	old_plane = data->map->player->plane.x;
	mlx_clear_window(data->g->mlx, data->g->win);
	if (dir)
	{
		data->map->player->dir.x = data->map->player->dir.x * cos(-rotSpeed)
			- data->map->player->dir.y * sin(-rotSpeed);
		data->map->player->dir.y = old_dir * sin(-rotSpeed)
			+ data->map->player->dir.y * cos(-rotSpeed);
		data->map->player->plane.x = data->map->player->plane.x * cos(-rotSpeed)
			- data->map->player->plane.y * sin(-rotSpeed);
		data->map->player->plane.y = old_plane * sin(-rotSpeed)
			+ data->map->player->plane.y * cos(-rotSpeed);
	}
	else
	{
		data->map->player->dir.x = data->map->player->dir.x * cos(rotSpeed)
			- data->map->player->dir.y * sin(rotSpeed);
		data->map->player->dir.y = old_dir * sin(rotSpeed)
			+ data->map->player->dir.y * cos(rotSpeed);
		data->map->player->plane.x = data->map->player->plane.x * cos(rotSpeed)
			- data->map->player->plane.y * sin(rotSpeed);
		data->map->player->plane.y = old_plane * sin(rotSpeed)
			+ data->map->player->plane.y * cos(rotSpeed);
	}
}