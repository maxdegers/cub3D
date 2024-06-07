/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:39:59 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/07 16:51:41 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_map(t_map *map)
{
	if (map->map)
		ft_free_tab(map->map);
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
}

void	free_buf(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map->window.x)
	{
		free(data->buf[i]);
		i++;
	}
	free(data->buf);
}

void	free_tex(t_tex *tex, void *mlx)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tex[i].img)
			mlx_destroy_image(mlx, tex[i].img);
		i++;
	}
	free(tex);
}

void	free_all(t_data *data)
{
	if (data->map)
		ft_free_map(data->map);
	if (data->tex)
		free_tex(data->tex, data->g->mlx);
	if (data->buf)
		free_buf(data);
	if (data->g)
		mlx_destroyer(data->g);
}
