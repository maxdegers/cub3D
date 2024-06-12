/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:54:42 by gberthol          #+#    #+#             */
/*   Updated: 2024/06/12 10:54:42 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int key, t_data *data)
{
	if (key == 65307)
		close_window(data->g);
	else if (key == 'w')
		data->mv_up = True;
	else if (key == 's')
		data->mv_down = True;
	else if (key == 'a')
		data->mv_left = True;
	else if (key == 'd')
		data->mv_right = True;
	else if (key == 65361)
		data->rot_left = True;
	else if (key == 65363)
		data->rot_right = True;
	else if (key == 65451)
		data->map->zoom += 1;
	else if (key == 65453)
		data->map->zoom -= 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == 'w')
		data->mv_up = False;
	else if (key == 's')
		data->mv_down = False;
	else if (key == 'a')
		data->mv_left = False;
	else if (key == 'd')
		data->mv_right = False;
	else if (key == 65361)
		data->rot_left = False;
	else if (key == 65363)
		data->rot_right = False;
	return (0);
}
