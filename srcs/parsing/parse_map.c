/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:48:34 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/30 13:00:11 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int	go_to_map(char *line, int *i)
{
	char	c;
	int		start;

	while (line[*i])
	{
		start = *i;
		while (line[*i] != '\0' && line[*i] != '\n')
			(*i)++;
		c = line[*i];
		line[*i] = '\0';
		if (is_map(&line[start]) == 0)
		{
			line[*i] = c;
			*i = start;
			return (1);
		}
		line[*i] = c;
		if (line[*i] != '\0')
			(*i)++;
	}
	return (0);
}

static void	ft_nl_chec(char *line, t_data *data)
{
	int		i;
	int		bool;

	i = -1;
	bool = 0;
	while (line[++i])
	{
		if (bool == 0 && go_to_map(line, &i) == 1)
			bool = 1;
		if (bool == 1 && line[i] == '\n' && line[i + 1] == '\n')
			return (exit_error(ERROR_MAP_NL, data));
	}
}

void	ft_parse_file(char *path, t_data *data)
{
	char	*file;
	char	**lines;
	int		i;

	file = get_file(path);
	ft_nl_chec(file, data);
	lines = ft_split(file, '\n');
	free(file);
	if (!lines)
		exit_error(ERROR_MALLOC, data);
	i = 0;
	while (lines[i])
	{
		ft_parse_line(lines[i], data, lines);
		i++;
	}
	ft_free_tab(lines);
}

int	parse_map(char *path, t_data *data)
{
	ft_setup_map(data);
	if (ft_check_file(path, data) == 1)
		return (1);
	ft_parse_file(path, data);
	if (check_data(data) == 1)
		return (1);
	data->map->c.rgb = rgb_to_int(data->map->c.r,
			data->map->c.g, data->map->c.b);
	data->map->f.rgb = rgb_to_int(data->map->f.r,
			data->map->f.g, data->map->f.b);
	return (0);
}
