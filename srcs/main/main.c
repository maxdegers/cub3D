/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:16:54 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/24 20:55:41 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_init_mlx(t_data *data)
{
	data->g->mlx = mlx_init();
	if (!data->g->mlx)
		return (free_all(data), ft_perror());
	data->g->win = mlx_new_window(data->g->mlx, data->map->window.x,
			data->map->window.y, "cub3D");
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		return (ft_puterror(ERROR_ARG), 1);
	data.map = &map;
	data.g = &mlx;
	if (parse_map(argv[1], &data) == 1)
		return (free_all(&data), EXIT_FAILURE);
	ft_init_mlx(&data);
	main_loop(&data, &mlx);
	return (EXIT_SUCCESS);
}
