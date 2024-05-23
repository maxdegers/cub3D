/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 12:16:54 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/18 17:34:07 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char const *argv[])
{
	if (argc != 3)
		return (ft_puterror(ERROR_ARG), 1);
	(void)argv;
	return (0);
}
