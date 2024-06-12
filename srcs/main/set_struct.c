/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:02:25 by gberthol          #+#    #+#             */
/*   Updated: 2024/06/11 16:02:25 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_image(t_data *data, t_tex *tex)
{
	tex->img = mlx_xpm_file_to_image(data->g->mlx,
			tex->file, &tex->width, &tex->height);
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
	return (0);
}

void	set_player_cam(t_player *player)
{
	player->dir.x = 0;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0;
}

void	set_player(t_data *data, t_player *player)
{
	set_player_cam(player);
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
	player->mov_speed = MOVE_SPEED;
	player->rot_speed = ROTATE_SPEED;
}
