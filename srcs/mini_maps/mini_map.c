/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:17:31 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/31 19:09:23 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	mlx_pixel_put(data->g->mlx, data->g->win, x, y, color);
}

void	put_block(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	ft_put_player(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			my_mlx_pixel_put(data, data->map->player_pos.x * 10 + i, data->map->player_pos.y * 10 + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map_mini_map(t_map *map, t_data *data, int mini_map_width, int mini_map_height)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	(void)mini_map_width;
	(void)mini_map_height;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
			{
				x = j * 10;
				y = i * 10;
				put_block(data, x, y, 0x00FF00);
			}
			j++;
		}
		i++;
	}
	ft_put_player(data, 0x0000FF);
	
}

void	display_minimap(t_map *map, t_data *data)
{
	int		mini_map_width;
	int		mini_map_height;

	mini_map_width = map->window.x / 5;
	mini_map_height = map->window.y / 5;
	draw_map_mini_map(map, data, mini_map_width, mini_map_height);
}
