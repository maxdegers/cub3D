/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:48:34 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/24 13:31:27 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static	int	check_if_line_is_map(char *line, size_t	*start)
{
	int		i;
	char	c;

	i = *start;
	while (line[i] == '\n' || line[i] == '\0')
		i++;
	c = line[i];
	line[i] = '\0';
	if (is_map(&line[*start]) == 1)
	{
		line[i] = c;
		return (1);
	}
	line[i] = c;
	return (0);
}

static void	ft_nl_chec(char *line, t_data *data)
{
	int		i;
	int		bool;
	size_t	start;

	i = -1;
	bool = 0;
	start = 0;
	while (line[++i])
	{
		if (line[i] == '\n' && bool == 0)
			start = i;
		if (bool == 0 && check_if_line_is_map(line, &start) == 1)
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
	i = 0;
	while (lines[i])
	{
		// ft_parse_line(lines[i], data);
		i++;
	}
	free(file);
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
	return (0);
}
