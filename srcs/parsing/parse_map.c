/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:48:34 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/24 12:35:18 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static size_t	ft_get_map_size(char *map)
{
	int		fd;
	char	line[1024];
	size_t	size;
	ssize_t	sz;

	fd = open(map, 0);
	if (fd < 0)
	{
		perror("Error opening file");
		exit (1);
	}
	size = 0;
	sz = 1;
	while (sz > 0)
	{
		sz = read(fd, line, 1024);
		if (sz == -1)
			ft_perror();
		size += sz;
	}
	close(fd);
	return (size);
}

char	*get_file(char *path)
{
	int		fd;
	char	*line;
	size_t	size;
	int		i;

	size = ft_get_map_size(path);
	line = ft_calloc(size + 1, sizeof(char));
	fd = open(path, 0);
	i = read(fd, line, size);
	close(fd);
	return (line);
}

void	ft_parse_file(char *path, t_data *data)
{
	char	*file;
	char	**lines;
	int		i;

	file = get_file(path);
	lines = ft_split(file, '\n');
	i = 0;
	while (lines[i])
	{
		ft_parse_line(lines[i], data);
		i++;
	}
	free(file);
	ft_free_map(lines);
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
