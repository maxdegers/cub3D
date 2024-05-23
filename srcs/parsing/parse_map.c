/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:48:34 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 18:29:46 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parse_map(char *path, t_data *data)
{
	// int	fd;

	ft_setup_map(data);
	if (ft_check_file(path, data) == 1)
		return (1);
	// ft_parse_file(path, data);
	return (0);
}
