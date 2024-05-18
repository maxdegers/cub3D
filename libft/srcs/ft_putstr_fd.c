/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:02:07 by mpitot            #+#    #+#             */
/*   Updated: 2024/05/18 12:39:02 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}
