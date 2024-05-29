/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:52:17 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 14:19:20 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	setup_map(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->map = NULL;
	map->f.r = -1;
	map->f.g = -1;
	map->f.b = -1;
	map->c.r = -1;
	map->c.g = -1;
	map->c.b = -1;
	map->player_dir = 0;
	map->player_pos.x = -1;
	map->player_pos.y = -1;
	map->c.rgb = 0;
	map->f.rgb = 0;
	map->map = NULL;
	map->window.x = WIDTH;
	map->window.y = HEIGHT;
}

void	ft_setup_map(t_data *data)
{
	setup_map(data->map);
}
