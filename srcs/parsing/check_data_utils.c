/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gberthol <gberthol@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:13:21 by gberthol          #+#    #+#             */
/*   Updated: 2024/06/11 16:13:21 by gberthol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_map(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W')
			return (1);
		i++;
	}
	if (ft_strcmp(line, "") == 0)
		return (1);
	return (0);
}

size_t	get_line_longest(char **map)
{
	size_t	i;
	size_t	size;
	size_t	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		size = ft_strlen(map[i]);
		if (size > max)
			max = size;
		i++;
	}
	return (max);
}
