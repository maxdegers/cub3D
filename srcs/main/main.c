/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:16:54 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/05 15:37:36 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_init_mlx(t_data *data)
{
	data->mv_down = False;
	data->mv_up = False;
	data->mv_left = False;
	data->mv_right = False;
	data->rot_left = False;
	data->rot_right = False;
	data->g->mlx = mlx_init();
	if (!data->g->mlx)
		return (free_all(data), ft_perror());
	data->g->win = mlx_new_window(data->g->mlx, data->map->window.x,
			data->map->window.y, "cub3D");
	if (!data->g->win)
		return (free_all(data), mlx_destroyer(data->g), ft_perror());
}

static void	set_player(t_data *data, t_player *player)
{
	player->dir.x = 0;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0;
	if (data->map->player_dir == 'N')
	{
		player->dir.x = -1;
		player->plane.y = 0.66;
	}
	else if (data->map->player_dir == 'E')
	{
		player->dir.x = 1;
		player->plane.y = -0.66;
	}
	else if (data->map->player_dir == 'S')
	{
		player->dir.y = 1;
		player->plane.x = 0.66;
	}
	else if (data->map->player_dir == 'W')
	{
		player->dir.y = -1;
		player->plane.x = -0.66;
	}
	player->pos.x = data->map->player_pos.x;
	player->pos.y = data->map->player_pos.y;
	player->mov_speed = 0.1;
	player->rot_speed = 0.1;
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
	data.map->player = &player;
	if (parse_map(argv[1], &data) == 1)
		return (free_all(&data), EXIT_FAILURE);
	set_player(&data, &player);
	ft_init_mlx(&data);
	main_loop(&data, &mlx);
	free_all(&data);
	return (EXIT_SUCCESS);
}
