/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:52:17 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 15:01:28 by mbrousse         ###   ########.fr       */
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
	map->player_x = 0;
	map->player_y = 0;
	map->player_dir = 0;
	map->f.r = 0;
	map->f.g = 0;
	map->f.b = 0;
	map->c.r = 0;
	map->c.g = 0;
	map->c.b = 0;
	map->width = 0;
	map->height = 0;
	map->map = NULL;
}

void	ft_setup(t_data *data)
{
	setup_map(data->map);
}
