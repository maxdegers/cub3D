/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:27:29 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/24 13:28:44 by mbrousse         ###   ########.fr       */
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
	if (i == -1)
	{
		free(line);
		ft_perror();
	}
	close(fd);
	return (line);
}
