/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:10:03 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 16:00:19 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_position(char **map, size_t i, size_t j )
{
	if (j >= ft_strlen(map[i - 1])
		|| j >= ft_strlen(map[i + 1]))
		return (1);
	if (map[i - 1][j] == ' ')
		return (1);
	if (map[i + 1][j] == ' ')
		return (1);
	if (map[i][j - 1] == ' ')
		return (1);
	if (map[i][j + 1] == ' ')
		return (1);
	return (0);
}

int	check_border(char **map, size_t i, size_t j)
{
	if (i == 0 && (map[i][j] == '0' || map[i][j] == 'W'
		|| map[i][j] == 'E' || map[i][j] == 'S' || map[i][j] == 'N'))
		return (1);
	if (i == (size_t)ft_tablen(map) - 1 && (map[i][j] == '0'
		|| map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S'
		|| map[i][j] == 'N'))
		return (1);
	if (j == 0 && (map[i][j] == '0' || map[i][j] == 'W'
		|| map[i][j] == 'E' || map[i][j] == 'S' || map[i][j] == 'N'))
		return (1);
	if (j == ft_strlen(map[i]) - 1 && (map[i][j] == '0'
		|| map[i][j] == 'W' || map[i][j] == 'E'
		|| map[i][j] == 'S' || map[i][j] == 'N'))
		return (1);
	return (0);
}
