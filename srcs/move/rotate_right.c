/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:25:12 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 06:40:10 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotate_r(t_data *data)
{
    t_player	*player;
    double		old_dir_x;
    double		old_plane_x;

    player = data->map->player;
    old_dir_x = player->dir.x;
    player->dir.x = player->dir.x * cos(-ROTATE_SPEED) - player->dir.y * sin(-ROTATE_SPEED);
    player->dir.y = old_dir_x * sin(-ROTATE_SPEED) + player->dir.y * cos(-ROTATE_SPEED);
    old_plane_x = player->plane.x;
    player->plane.x = player->plane.x * cos(-ROTATE_SPEED) - player->plane.y * sin(-ROTATE_SPEED);
    player->plane.y = old_plane_x * sin(-ROTATE_SPEED) + player->plane.y * cos(-ROTATE_SPEED);
}
