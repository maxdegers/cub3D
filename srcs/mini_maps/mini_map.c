/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:17:31 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/31 18:30:01 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	mlx_pixel_put(data->g->mlx, data->g->win, x, y, color);
}

void	draw_square(t_data *data, int x, int y, int width, int height, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < width)
	{
		j = 0;
		while (j < height)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map_mini_map(t_map *map, t_data *data, int mini_map_width, int mini_map_height)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = 0;
	while (x < map->window.x)
	{
		y = 0;
		i = x / 5;
		while (y < map->window.y)
		{
			j = y / 5;
			if (map->map[j][i] == '1')
				draw_square(data, x, y, mini_map_width, mini_map_height, 0x00FF00);
			else if (map->map[j][i] == '0')
				draw_square(data, x, y, mini_map_width, mini_map_height, 0x000000);
			else if (map->map[j][i] == '2')
				draw_square(data, x, y, mini_map_width, mini_map_height, 0xFF0000);
			y++;
		}
		x++;
	}
}

void	display_minimap(t_map *map, t_data *data)
{
	int		mini_map_width;
	int		mini_map_height;

	mini_map_width = map->window.x / 5;
	mini_map_height = map->window.y / 5;
	draw_map_mini_map(map, data, mini_map_width, mini_map_height);
}
