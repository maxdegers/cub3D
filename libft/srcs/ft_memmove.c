/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:20:37 by mpitot            #+#    #+#             */
/*   Updated: 2024/05/18 12:38:42 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src < dest)
	{
		while (n-- > 0)
		{
			((unsigned char *) dest)[n] = ((unsigned char *) src)[n];
		}
	}
	else if (src > dest)
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
