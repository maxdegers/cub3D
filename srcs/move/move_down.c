/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:23:59 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/06 13:48:35 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_d(t_data *data)
{
	t_player	*player;

	player = data->map->player;
	if (data->map->map[(int)(player->pos.x - player->dir.x * player->mov_speed)][(int)player->pos.y] == '0')
		player->pos.x -= player->dir.x * player->mov_speed;
	if (data->map->map[(int)player->pos.x][(int)(player->pos.y - player->dir.y * player->mov_speed)] == '0')
		player->pos.y -= player->dir.y * player->mov_speed;
}