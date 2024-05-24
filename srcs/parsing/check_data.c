/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:35:34 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/24 13:15:40 by mbrousse         ###   ########.fr       */
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
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
			return (1);
		i++;
	}
	return (0);
}

static	check_map(t_data *data)
{
	size_t	i;
	
	i = 0;
	while (data->map->map[i] != NULL)
	{
		if (is_map(data->map->map[i]) == 1)
			return (ft_puterror(ERROR_MAP_CHAR), 1);
		i++;
	}
	return (0);	
}

int	check_data(t_data *data)
{
	if (data->map->no == NULL)
		return (ft_puterror(ERROR_NO_PATH), 1);
	if (data->map->so == NULL)
		return (ft_puterror(ERROR_SO_PATH), 1);
	if (data->map->we == NULL)
		return (ft_puterror(ERROR_WE_PATH), 1);
	if (data->map->ea == NULL)
		return (ft_puterror(ERROR_EA_PATH), 1);
	if (data->map->c.b == -1 || data->map->c.g == -1 || data->map->c.r == -1)
		return (ft_puterror(ERROR_C_COLOR), 1);
	if (data->map->f.b == -1 || data->map->f.g == -1 || data->map->f.r == -1)
		return (ft_puterror(ERROR_F_COLOR), 1);
	if (data->map->c.b < 0 || data->map->c.b > 255 || data->map->c.g < 0
		|| data->map->c.g > 255 || data->map->c.r < 0 || data->map->c.r > 255)
		return (ft_puterror(ERROR_C_COLOR), 1);
	if (data->map->f.b < 0 || data->map->f.b > 255 || data->map->f.g < 0
		|| data->map->f.g > 255 || data->map->f.r < 0 || data->map->f.r > 255)
		return (ft_puterror(ERROR_F_COLOR), 1);
	if (check_map(data) == 1)
		return (1);
	return (0);
}
