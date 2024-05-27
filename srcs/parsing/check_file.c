/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:44:06 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 18:42:56 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	check_path_type(char *file, char *type)
{
	int	file_len;
	int	type_len;
	int	total_len;

	file_len = ft_strlen(file);
	type_len = ft_strlen(type);
	total_len = file_len - type_len;
	if (ft_strncmp(file + total_len, type, type_len) > 0)
		return (ft_puterror(ERROR_FILE_EXT), 1);
	if (file_len <= type_len)
		return (ft_puterror(ERROR_FILE_NAME), 1);
	return (0);
}

int	check_path_exist(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_puterror(ERROR_FILE_OPEN), 1);
	close(fd);
	return (0);
}

int	ft_check_file(char *path, t_data *data)
{
	(void)data;
	if (check_path_type(path, ".cub") == 1)
		return (1);
	if (check_path_exist(path) == 1)
		return (1);
	return (0);
}
