/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:35:20 by mbrousse          #+#    #+#             */
/*   Updated: 2024/06/05 15:08:58 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	ft_add_to_map(char *line, t_data *data)
{
	char	**tmp;
	int		i;

	tmp = data->map->map;
	data->map->map = ft_calloc(ft_tablen(tmp) + 2, sizeof(char *));
	if (!data->map->map)
		return (ft_free_tab(tmp), 1);
	i = 0;
	while (tmp != NULL && *tmp != NULL && tmp[i])
	{
		data->map->map[i] = ft_strdup(tmp[i]);
		i++;
	}
	data->map->map[i] = ft_strdup(line);
	if (!data->map->map[i])
		return (ft_free_tab(tmp), 1);
	data->map->map[i + 1] = NULL;
	ft_free_tab(tmp);
	return (0);
}

int	ft_striscolor(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	i = ft_atoi(str);
	if (i < 0 || i > 255)
		return (0);
	return (1);
}
