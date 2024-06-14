/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:24:38 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/14 10:03:59 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_r(t_data *data)
{
	t_player	*player;

	player = data->map->player;
	if (data->map->map[(int)(data->map->player->pos.x
			+ data->map->player->dir.y * player->mov_speed)][
			(int)data->map->player->pos.y] == '0')
		player->pos.x += player->dir.y * data->map->player->mov_speed;
	if (data->map->map[(int)player->pos.x][
		(int)(player->pos.y + player->dir.x * player->mov_speed)] == '0')
		player->pos.y -= player->dir.x * data->map->player->mov_speed;
}
