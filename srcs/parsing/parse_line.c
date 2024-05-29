/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:32:27 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/29 10:10:54 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_add_color(t_color *color, int value)
{
	if (color->r == -1)
		color->r = value;
	else if (color->g == -1)
		color->g = value;
	else if (color->b == -1)
		color->b = value;
}

static void	parse_color(char **split, t_data *data, int dir, char **lines)
{
	t_color	color;
	char	**split2;

	color.r = -1;
	color.g = -1;
	color.b = -1;
	split2 = ft_split(split[1], ',');
	if (!split2)
		return (ft_free_tab(split), ft_free_tab(lines),
			exit_error(ERROR_MALLOC, data));
	if (ft_tablen(split2) != 3)
		return (ft_free_tab(split), ft_free_tab(split2),
			ft_free_tab(lines), exit_error(ERROR_MAP_CHAR, data));
	ft_add_color(&color, ft_atoi(split2[0]));
	ft_add_color(&color, ft_atoi(split2[1]));
	ft_add_color(&color, ft_atoi(split2[2]));
	ft_free_tab(split2);
	if (dir == FLOOR && data->map->f.b == -1)
		data->map->f = color;
	else if (dir == CEILING && data->map->c.b == -1)
		data->map->c = color;
	else
		return (ft_free_tab(split), ft_free_tab(lines),
			exit_error(ERROR_FILE_CONTENT, data));
}

static int	parse_arg(char **split, t_data *data, char **lines)
{
	if (ft_tablen(split) != 2)
		return (ft_puterror(ERROR_MAP_CHAR), 1);
	if (split[1] == NULL)
		return (ft_puterror(ERROR_FILE_CONTENT), 1);
	if (ft_strcmp(split[0], "NO") == 0)
		parse_texture(split, data, NORTH, lines);
	else if (ft_strcmp(split[0], "SO") == 0)
		parse_texture(split, data, SOUTH, lines);
	else if (ft_strcmp(split[0], "WE") == 0)
		parse_texture(split, data, WEST, lines);
	else if (ft_strcmp(split[0], "EA") == 0)
		parse_texture(split, data, EAST, lines);
	else if (ft_strcmp(split[0], "F") == 0)
		parse_color(split, data, FLOOR, lines);
	else if (ft_strcmp(split[0], "C") == 0)
		parse_color(split, data, CEILING, lines);
	else
		return (ft_puterror(ERROR_FILE_CONTENT), 1);
	ft_free_tab(split);
	return (0);
}

void	ft_parse_line(char *line, t_data *data, char **lines)
{
	char		**split;
	static int	bool = 0;

	if (is_map(line) == 0)
	{
		if (ft_add_to_map(line, data) == 1)
			return (ft_free_tab(lines), exit_error(ERROR_MALLOC, data));
		bool = 1;
	}
	else if (bool == 1)
		return (ft_free_tab(lines), exit_error(ERROR_FILE_CONTENT, data));
	else
	{
		split = ft_split(line, ' ');
		if (!split)
			return (ft_free_tab(lines), exit_error(ERROR_MALLOC, data));
		if (parse_arg(split, data, lines) == 1)
			return (ft_free_tab(lines), ft_free_tab(split),
				exit_error(NULL, data));
	}
}
