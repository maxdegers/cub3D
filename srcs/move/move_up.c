/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:23:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/06 13:49:03 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_u(t_data *data)
{
	if (data->map->map[(int)(data->map->player->pos.x
			+ data->map->player->dir.x
			* data->map->player->mov_speed)][
			(int)data->map->player->pos.y] == '0')
		data->map->player->pos.x += data->map->player->dir.x
			* data->map->player->mov_speed;
	if (data->map->map[(int)data->map->player->pos.x][
		(int)(data->map->player->pos.y + data->map->player->dir.y
		* data->map->player->mov_speed)] == '0')
		data->map->player->pos.y += data->map->player->dir.y
			* data->map->player->mov_speed;
}
