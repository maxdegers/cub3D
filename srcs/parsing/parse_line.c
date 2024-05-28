/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:32:27 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 22:12:42 by mbrousse         ###   ########.fr       */
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
	int		i;
	int		start;
	char	c;

	color.r = -1;
	color.g = -1;
	color.b = -1;
	i = 0;
	while (split[1][i])
	{
		start = i;
		while (split[1][i] && ft_isdigit(split[1][i]) == 0)
			i++;
		c = split[1][i];
		split[1][i] = '\0';
		ft_add_color(&color, ft_atoi(split[1] + start));
		split[1][i] = c;
		if (split[1][i] != '\0')
			i++;
	}
	if (dir == FLOOR)
		data->map->f = color;
	else if (dir == CEILING)
		data->map->c = color;
}

static void	parse_arg(char **split, t_data *data)
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
		exit_error(ERROR_MAP_CHAR, data);
}

void	ft_parse_line(char *line, t_data *data)
{
	char	**split;

	if (is_map(line) == 0)
		ft_add_to_map(line, data);
	else
	{
		split = ft_split(line, ' ');
		if (!split)
			exit_error(ERROR_MALLOC, data);
		if (ft_tablen(split) != 2)
			exit_error(ERROR_MAP_CHAR, data);
		if (split[1] == NULL)
			exit_error(ERROR_NO_PATH, data);
		parse_arg(split, data);
		ft_free_tab(split);
	}
}
