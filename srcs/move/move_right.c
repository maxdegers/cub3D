/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:24:38 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 06:39:18 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_move_r(t_data *data)
{
    t_player	*player;

    player = data->map->player;
    if (data->map->map[(int)(player->pos.x + player->plane.x * MOVE_SPEED)][(int)player->pos.y] != '1')
        player->pos.x += player->plane.x * MOVE_SPEED;
    if (data->map->map[(int)player->pos.x][(int)(player->pos.y + player->plane.y * MOVE_SPEED)] != '1')
        player->pos.y += player->plane.y * MOVE_SPEED;
}
