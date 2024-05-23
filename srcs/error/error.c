/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:23:46 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 14:59:33 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_puterror(char *message)
{
	ft_printf_fd(2, "%s", message);
}

void	ft_perror(void)
{
	perror("Error\n");
	exit(EXIT_FAILURE);
}

void	free_all(t_data *data)
{
	if (data->map)
		ft_free_map(data->map);
	// if (data->mlx)
	// 	free_mlx(data->mlx);
}

void	exit_error(char *message, t_data *data)
{
	ft_puterror(message);
	free_all(data);
	exit(1);
}
