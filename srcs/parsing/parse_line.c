/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:32:27 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/28 21:46:27 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	parse_texture(char **split, t_data *data, int dir)
{
	if (dir == NORTH)
	{
		data->map->no = ft_strdup(split[1]);
		if (!data->map->no)
			exit_error(ERROR_MALLOC, data);
	}
	else if (dir == SOUTH)
	{
		data->map->so = ft_strdup(split[1]);
		if (!data->map->so)
			exit_error(ERROR_MALLOC, data);
	}
	else if (dir == WEST)
	{
		data->map->we = ft_strdup(split[1]);
		if (!data->map->we)
			exit_error(ERROR_MALLOC, data);
	}
	else if (dir == EAST)
	{
		data->map->ea = ft_strdup(split[1]);
		if (!data->map->ea)
			exit_error(ERROR_MALLOC, data);
	}
}

static void	ft_add_color(t_color *color, int value)
{
	if (color->r == -1)
		color->r = value;
	else if (color->g == -1)
		color->g = value;
	else if (color->b == -1)
		color->b = value;
}

static void	parse_color(char **split, t_data *data, int dir)
{
	t_color	color;
	char	**split2;

	color.r = -1;
	color.g = -1;
	color.b = -1;
	split2 = ft_split(split[1], ',');
	if (!split2)
		return (ft_free_tab(split), exit_error(ERROR_MALLOC, data));
	if (ft_tablen(split2) != 3)
		return (ft_free_tab(split), ft_free_tab(split2),
			exit_error(ERROR_MAP_CHAR, data));
	ft_add_color(&color, ft_atoi(split2[0]));
	ft_add_color(&color, ft_atoi(split2[1]));
	ft_add_color(&color, ft_atoi(split2[2]));
	ft_free_tab(split2);
	if (dir == FLOOR)
		data->map->f = color;
	else if (dir == CEILING)
		data->map->c = color;
}

static int	parse_arg(char **split, t_data *data)
{
	if (ft_strcmp(split[0], "NO") == 0)
		parse_texture(split, data, NORTH);
	else if (ft_strcmp(split[0], "SO") == 0)
		parse_texture(split, data, SOUTH);
	else if (ft_strcmp(split[0], "WE") == 0)
		parse_texture(split, data, WEST);
	else if (ft_strcmp(split[0], "EA") == 0)
		parse_texture(split, data, EAST);
	else if (ft_strcmp(split[0], "F") == 0)
		parse_color(split, data, FLOOR);
	else if (ft_strcmp(split[0], "C") == 0)
		parse_color(split, data, CEILING);
	else
		return (1);
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
		if (ft_tablen(split) != 2)
			return (ft_free_tab(lines), exit_error(ERROR_MAP_CHAR, data));
		if (split[1] == NULL)
			return (ft_free_tab(split), ft_free_tab(lines),
				exit_error(ERROR_FILE_CONTENT, data));
		if (parse_arg(split, data) == 1)
			return (ft_free_tab(lines), ft_free_tab(split),
				exit_error(ERROR_MAP_CHAR, data));
	}
}
