/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:06:05 by mpitot            #+#    #+#             */
/*   Updated: 2024/05/18 12:38:31 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	temp;

	if (!lst)
		return (0);
	i = 1;
	temp = *lst;
	while (temp.next)
	{
		temp = *temp.next;
		i++;
	}
	return (i);
}
