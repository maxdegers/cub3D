/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:24:55 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/06 10:08:10 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotate_l(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->map->player->dir.x;
	data->map->player->dir.y = old_dir_x
		* sin(data->map->player->rot_speed) + data->map->player->dir.y
		* cos(data->map->player->rot_speed);
	old_plane_x = data->map->player->plane.x;
	data->map->player->plane.x = data->map->player->plane.x
		* cos(data->map->player->rot_speed) - data->map->player->plane.y
		* sin(data->map->player->rot_speed);
	data->map->player->plane.y = old_plane_x
		* sin(data->map->player->rot_speed) + data->map->player->plane.y
		* cos(data->map->player->rot_speed);
	data->map->player->dir.x = data->map->player->dir.x
		* cos(data->map->player->rot_speed) - data->map->player->dir.y
		* sin(data->map->player->rot_speed);
}

void	ft_mouse_rotate_l(t_data *data, int x)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = (WIDTH / 2 - x);
	rot_speed /= WIDTH / 1.2;
	old_dir_x = data->map->player->dir.x;
	data->map->player->dir.x = data->map->player->dir.x
		* cos(rot_speed) - data->map->player->dir.y * sin(rot_speed);
	data->map->player->dir.y = old_dir_x
		* sin(rot_speed) + data->map->player->dir.y * cos(rot_speed);
	old_plane_x = data->map->player->plane.x;
	data->map->player->plane.x = data->map->player->plane.x
		* cos(rot_speed) - data->map->player->plane.y * sin(rot_speed);
	data->map->player->plane.y = old_plane_x
		* sin(rot_speed) + data->map->player->plane.y * cos(rot_speed);
}
