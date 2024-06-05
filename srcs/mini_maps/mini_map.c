/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:17:31 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/04 21:50:52 by mbrousse         ###   ########.fr       */
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
			my_mlx_pixel_put(data, data->map->player_pos.x * data->mm->wsize + i, data->map->player_pos.y * data->mm->wsize + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(char **map, t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
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

void	init_image(t_im *img, t_data *data)
{
	img->img = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
	img->img = mlx_new_image(data->g->mlx,
			WIDTH, HEIGHT);
	if (!img->img)
		exit_error(ERROR_MALLOC, data);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		mlx_destroy_image(data->g->mlx, data->g->img->img);
		exit_error(ERROR_MLX, data);
	}
}

void	display_minimap(t_map *map, t_data *data)
{
	t_mm	mm;
	t_im	img;
	
	data->mm = &mm;
	data->g->img = &img;
	(void)map;
	if (data->map->zoom < 0)
		data->map->zoom = 0;
	if (data->map->zoom > 10)
		data->map->zoom = 10;
	mm.psize = data->map->zoom * 0.5;
	mm.wsize = data->map->zoom * 1.5;
	// mm->map = get_mini_map(map, data, mm);
	init_image(data->g->img, data);
	draw_minimap(data->map->map, data);
	mlx_put_image_to_window(data->g->mlx, data->g->win, data->g->img->img, 0, 0);
	// ft_free_tab(mm->map);
	mlx_destroy_image(data->g->mlx, data->g->img->img);

}
