/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:17:31 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 11:02:13 by mbrousse         ###   ########.fr       */
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
	while (i < data->mm->wsize)
	{
		j = 0;
		while (j < data->mm->wsize)
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
	while (i < data->mm->psize)
	{
		j = 0;
		while (j < data->mm->psize)
		{
			my_mlx_pixel_put(data, data->map->player_pos.x * data->mm->wsize + i, data->map->player_pos.y * data->mm->wsize + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_map *map, t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
			{
				x = j * data->mm->wsize;
				y = i * data->mm->wsize;
				put_block(data, x, y, 0x00FF00);
			}
			j++;
		}
		i++;
	}
	ft_put_player(data, 0x0000FF);
	
}

// void	get_mini_map(t_map *map, t_data *data, t_mm *mm)
// {
	
// }

void	display_minimap(t_map *map, t_data *data)
{
	t_mm	mm; // mini map psize 7 and wsize 60 for 1920x1080.
	
	(void)map;
	data->mm = &mm;
	mm.x = 0;
	mm.y = 0;
	if (data->map->zoom < 1)
		data->map->zoom = 1;
	if (data->map->zoom > 30)
		data->map->zoom = 30;
	mm.psize = data->map->zoom / 2;
	mm.wsize = data->map->zoom * 4;
	// mm->map = get_mini_map(map, data, mm);
	draw_minimap(map, data);
	// ft_free_tab(mm->map);
}
