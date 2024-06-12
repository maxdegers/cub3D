/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:23:46 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/07 13:46:49 by mbrousse         ###   ########.fr       */
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

void	exit_error(char *message, t_data *data)
{
	ft_puterror(message);
	free_all(data);
	exit(1);
}
