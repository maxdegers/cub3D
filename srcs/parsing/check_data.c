/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:35:34 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/06 14:35:56 by mbrousse         ###   ########.fr       */
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

static int	ft_check_map_borders(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (check_border(map, i, j) == 1)
				return (1);
			if (map[i][j] == '0' || map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S' || map[i][j] == 'N')
			{
				if (check_position(map, i, j) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_map(t_data *data)
{
	size_t	i;
	size_t	j;
	int		b;

	i = 0;
	b = 0;
	if (ft_check_map_borders(data->map->map) == 1)
		return (ft_puterror(ERROR_MAP_BORDER), 1);
	while (data->map->map[i] != NULL)
	{
		j = -1;
		while (data->map->map[i][++j])
		{
			if (ft_check_if_is_player(data, i, j, b) == 1)
			{
				if (b == 1)
					return (ft_puterror(ERROR_MAP_CHAR), 1);
				b = 1;
			}
		}
		if (is_map(data->map->map[i]) == 1)
			return (ft_puterror(ERROR_MAP_CHAR), 1);
		i++;
	}
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

char	*ft_set_new_line(char *line, int size)
{
	char	*new_line;
	int		i;

	i = 0;
	new_line = malloc(sizeof(char) * (size + 1));
	if (new_line == NULL)
		return (NULL);
	while (line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	while (i < size)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

void	make_map_rect(t_data *data)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = get_line_longest(data->map->map);
	while (data->map->map[i])
	{
		if (ft_strlen(data->map->map[i]) < size)
		{
			data->map->map[i] = ft_set_new_line(data->map->map[i], size);
			if (data->map->map[i] == NULL)
				exit_error(ERROR_MALLOC, data);
		}
		i++;
	}
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
	if (data->map->player_dir == 0)
		return (ft_puterror(ERROR_MAP_PLAYER), 1);
	if (check_texture(data) == 1)
		return (1);
	make_map_rect(data);
	return (0);
}
