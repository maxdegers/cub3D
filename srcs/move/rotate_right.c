/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 06:25:12 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/06 14:18:18 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_rotate_r(t_data *data)
{
    double oldDirX = data->map->player->dir.x;
    data->map->player->dir.x = data->map->player->dir.x * cos(-data->map->player->rot_speed) - data->map->player->dir.y * sin(-data->map->player->rot_speed);
    data->map->player->dir.y = oldDirX * sin(-data->map->player->rot_speed) + data->map->player->dir.y * cos(-data->map->player->rot_speed);
    double oldPlaneX = data->map->player->plane.x;
    data->map->player->plane.x = data->map->player->plane.x * cos(-data->map->player->rot_speed) - data->map->player->plane.y * sin(-data->map->player->rot_speed);
    data->map->player->plane.y = oldPlaneX * sin(-data->map->player->rot_speed) + data->map->player->plane.y * cos(-data->map->player->rot_speed);
}
