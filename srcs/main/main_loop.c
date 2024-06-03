/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:30:10 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 10:42:11 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "calcul.h"

int	key_p(int key, t_data *data)
{
	printf("key: %d\n", key);
	if (key == 65307)
		close_window(data->g);
	else if (key == 'w')
		ft_move_u(data);
	else if (key == 's')
		ft_move_d(data);
	else if (key == 'a')
		ft_move_l(data);
	else if (key == 'd')
		ft_move_r(data);
	else if (key == 65361)
		ft_rotate_l(data);
	else if (key == 65363)
		ft_rotate_r(data);
	else if (key == 65451) // +
		data->map->zoom += 1;
	else if (key == 65453) // -
		data->map->zoom -= 1;
	return (0);
}

int	ft_generate(t_data *data)
{
	// display_column(data->map, data);
	display_minimap(data->map, data);
	return (0);
}

int	main_loop(t_data *data, t_mlx *cub)
{
	mlx_loop_hook(cub->mlx, ft_generate, data);
	mlx_hook(cub->win, 17, 1L << 0, close_window, data->g);
	mlx_hook(cub->win, 2, 1L << 0, key_p, data);
	mlx_loop(cub->mlx);
	mlx_destroyer(cub);
	return (0);
}
