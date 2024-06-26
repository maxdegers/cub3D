/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:01:20 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 10:49:43 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lsize;

	if (!little[0])
		return ((char *) big);
	if (len == 0)
		return (0);
	i = 0;
	lsize = ft_strlen(little);
	while (big[i] && i < len - lsize + 1)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j])
			j++;
		if (!little[j])
			return (&((char *) big)[i]);
		i++;
	}
	return (NULL);
}
