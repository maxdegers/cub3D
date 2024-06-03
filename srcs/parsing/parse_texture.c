/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 09:44:07 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/03 07:09:34 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	parse_texture_extent(char **split, t_data *data,
	int dir, char **lines)
{
	if (dir == EAST && data->map->ea == NULL)
	{
		data->map->ea = ft_strdup(split[1]);
		if (!data->map->ea)
			return (ft_free_tab(lines), ft_free_tab(split),
				exit_error(ERROR_MALLOC, data));
	}
	else
	{
		printf("Error\n");
		return (ft_free_tab(split), ft_free_tab(lines),
			exit_error(ERROR_FILE_CONTENT, data));
	}
}

void	parse_texture(char **split, t_data *data, int dir, char **lines)
{
	if (dir == NORTH && data->map->no == NULL)
	{
		data->map->no = ft_strdup(split[1]);
		if (!data->map->no)
			return (ft_free_tab(lines), ft_free_tab(split),
				exit_error(ERROR_MALLOC, data));
	}
	else if (dir == SOUTH && data->map->so == NULL)
	{
		data->map->so = ft_strdup(split[1]);
		if (!data->map->so)
			return (ft_free_tab(lines), ft_free_tab(split),
				exit_error(ERROR_MALLOC, data));
	}
	else if (dir == WEST && data->map->we == NULL)
	{
		data->map->we = ft_strdup(split[1]);
		if (!data->map->we)
			return (ft_free_tab(lines), ft_free_tab(split),
				exit_error(ERROR_MALLOC, data));
	}
	else
		parse_texture_extent(split, data, dir, lines);
}

int	check_texture(t_data *data)
{
	if (check_path_exist(data->map->no) == 1)
		return (1);
	if (check_path_exist(data->map->so) == 1)
		return (1);
	if (check_path_exist(data->map->we) == 1)
		return (1);
	if (check_path_exist(data->map->ea) == 1)
		return (1);
	if (check_path_type(data->map->no, ".xpm") == 1)
		return (1);
	if (check_path_type(data->map->so, ".xpm") == 1)
		return (1);
	if (check_path_type(data->map->we, ".xpm") == 1)
		return (1);
	if (check_path_type(data->map->ea, ".xpm") == 1)
		return (1);
	return (0);
}
