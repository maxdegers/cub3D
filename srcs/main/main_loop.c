/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:30:10 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/10 14:54:53 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "calcul.h"

void	mv_player(t_data *data)
{
	if (data->mv_up == True)
		ft_move_u(data);
	if (data->mv_down == True)
		ft_move_d(data);
	if (data->mv_left == True)
		ft_move_l(data);
	if (data->mv_right == True)
		ft_move_r(data);
	if (data->rot_left == True)
		ft_rotate_l(data);
	if (data->rot_right == True)
		ft_rotate_r(data);
}

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

int	mouse_handler(t_data *data)
{
	int	x;
	int	y;

	if (data->pause)
		return (mlx_mouse_show(data->g->mlx, data->g->win), 0);
	mlx_mouse_hide(data->g->mlx, data->g->win);
	mlx_mouse_get_pos(data->g->mlx, data->g->win, &x, &y);
	if (x != WIDTH / 2)
	{
		if (x > (WIDTH / 2))
			ft_mouse_rotate_r(data, x);
		else if (x < (WIDTH / 2))
			ft_mouse_rotate_l(data, x);
		mlx_mouse_move(data->g->mlx, data->g->win, WIDTH / 2, HEIGHT / 2);
	}
	else if (y != HEIGHT / 2)
		mlx_mouse_move(data->g->mlx, data->g->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}

int	ft_generate(t_data *data)
{
	t_im	img;

	data->g->img = &img;
	init_image(data->g->img, data);
	mouse_handler(data);
	mv_player(data);
	recast2(data);
	mlx_destroy_image(data->g->mlx, data->g->img->img);
	return (0);
}

int	main_loop(t_data *data, t_mlx *cub)
{
	mlx_loop_hook(cub->mlx, ft_generate, data);
	mlx_hook(cub->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(cub->win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(cub->win, 17, 1L << 0, close_window, data->g);
	mlx_loop(cub->mlx);
	return (0);
}
