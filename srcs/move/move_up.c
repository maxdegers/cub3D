/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:23:41 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 06:39:29 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_u(t_data *data)
{
    t_player	*player;

    player = data->map->player;
    if (data->map->map[(int)(player->pos.x + player->dir.x * MOVE_SPEED)][(int)player->pos.y] != '1')
        player->pos.x += player->dir.x * MOVE_SPEED;
    if (data->map->map[(int)player->pos.x][(int)(player->pos.y + player->dir.y * MOVE_SPEED)] != '1')
        player->pos.y += player->dir.y * MOVE_SPEED;
}
