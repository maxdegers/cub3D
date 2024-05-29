/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:16:54 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 14:13:25 by mbrousse         ###   ########.fr       */
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

static void	set_player(t_data *data, t_player *player)
{
	if (data->map->player_dir == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
	}
	else if (data->map->player_dir == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
	else if (data->map->player_dir == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (data->map->player_dir == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	player->pos.x = data->map->player_pos.x;
	player->pos.y = data->map->player_pos.y;
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_map		map;
	t_mlx		mlx;
	t_player	player;

	if (argc != 2)
		return (ft_puterror(ERROR_ARG), 1);
	data.map = &map;
	data.g = &mlx;
	if (parse_map(argv[1], &data) == 1)
		return (free_all(&data), EXIT_FAILURE);
	data.map->player = &player;
	set_player(&data, &player);
	ft_init_mlx(&data);
	main_loop(&data, &mlx);
	free_all(&data);
	return (EXIT_SUCCESS);
}
