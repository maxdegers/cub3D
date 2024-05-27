/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:35:20 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/27 22:00:19 by mbrousse         ###   ########.fr       */
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

void	ft_add_to_map(char *line, t_data *data)
{
	char	**tmp;
	int		i;

	tmp = data->map->map;
	data->map->map = ft_calloc(ft_tablen(tmp) + 2, sizeof(char *));
	if (!data->map->map)
		exit_error(ERROR_MALLOC, data);
	i = 0;
	while (tmp && tmp[i])
	{
		data->map->map[i] = tmp[i];
		i++;
	}
	data->map->map[i] = ft_strdup(line);
	if (!data->map->map[i])
		exit_error(ERROR_MALLOC, data);
	data->map->map[i + 1] = NULL;
	ft_free_tab(tmp);
}
