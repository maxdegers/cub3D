/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:16:54 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/10 15:10:52 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	set_buf(t_data *data)
// {
// 	uint32_t	i;

// 	i = 0;
// 	data->buf = malloc(sizeof(uint32_t *) * HEIGHT);
// 	if (!data->buf)
// 		return (1);
// 	while (i < HEIGHT)
// 	{
// 		data->buf[i] = malloc(sizeof(uint32_t) * WIDTH);
// 		if (!data->buf[i])
// 		{
// 			while (i != 0)
// 			{
// 				free(data->buf[i]);
// 				i--;
// 			}
// 			free(data->buf[i]);
// 			free(data->buf);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

void	get_image(t_data *data, t_tex *tex)
{
	tex->img = mlx_xpm_file_to_image(data->g->mlx, tex->file, &tex->width, &tex->height);
	if (!tex->img)
		return (free_all(data), mlx_destroyer(data->g), ft_perror());
	tex->tex_addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	if (!tex->tex_addr)
		return (free_all(data), mlx_destroyer(data->g), ft_perror());
	tex->data = (uint32_t *)tex->tex_addr;
}


int	set_texture(t_data *data)
{
	// if (set_buf(data) == 1)
	// 	return (1);
	data->tex = malloc(sizeof(t_tex) * 4);
	if (!data->tex)
		return (1);
	data->tex[0].file = data->map->no;
	data->tex[1].file = data->map->so;
	data->tex[2].file = data->map->we;
	data->tex[3].file = data->map->ea;
	get_image(data, &data->tex[1]);
	get_image(data, &data->tex[0]);
	get_image(data, &data->tex[2]);
	get_image(data, &data->tex[3]);
	// (void)data;
	return (0);
}

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
	if (set_texture(data) == 1)
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
