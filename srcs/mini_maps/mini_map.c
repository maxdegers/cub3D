/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:17:31 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/06 15:07:30 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->g->img->addr + (y * data->g->img->line_length + x * (
				data->g->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
			my_mlx_pixel_put(data, data->map->player->pos.y * data->mm->wsize + i, data->map->player->pos.x * data->mm->wsize + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(char **map, t_data *data)
{
	int		i;
	int		j;
	int		y;
	int		x;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				x = (j * data->mm->wsize);
				y = (i * data->mm->wsize);
				put_block(data, x, y, data->map->f.rgb);
			}
			if (map[i][j] == '0')
			{
				x = (j * data->mm->wsize);
				y = (i * data->mm->wsize);
				put_block(data, x, y, 0xA2B5B2);
			}
			j++;
		}
		i++;
	}
	ft_put_player(data, RED);
	
}

void	display_minimap(t_map *map, t_data *data)
{
	t_mm	mm;
	
	data->mm = &mm;
	(void)map;
	if (data->map->zoom < 0)
		data->map->zoom = 0;
	if (data->map->zoom > 10)
		data->map->zoom = 10;
	mm.psize = data->map->zoom * 0.5;
	mm.wsize = data->map->zoom * 1.5;
	draw_minimap(data->map->map, data);
}
