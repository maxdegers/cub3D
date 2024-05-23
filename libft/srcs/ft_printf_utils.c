/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:35:26 by mbrousse          #+#    #+#             */
/*   Updated: 2024/05/23 10:49:43 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

int	ft_putchar(int c)
{
	return ((int) write(1, &c, 1));
}

int	ft_putnbr_u(unsigned int n)
{
	int		x;
	int		y;

	if (n < 10)
		return (ft_putchar((int) n + 48));
	x = ft_putnbr_u(n / 10);
	if (x == -1)
		return (-1);
	y = ft_putchar(((int)(n % 10) + 48));
	if (y == -1)
		return (-1);
	return (x + y);
}

int	ft_putnbr(int n)
{
	int		x;
	int		y;

	if (n < 0)
	{
		x = ft_putchar('-');
		if (x == -1)
			return (-1);
		y = ft_putnbr_u(n * -1);
		if (y == -1)
			return (-1);
		return (x + y);
	}
	else
		return (ft_putnbr_u(n));
}

int	ft_putnbr_x(unsigned int nbr, char *base)
{
	int		x;
	int		y;

	if (nbr < 16)
		return (ft_putchar(base[nbr]));
	x = ft_putnbr_x(nbr / 16, base);
	if (x == -1)
		return (-1);
	y = ft_putchar(base[nbr % 16]);
	if (y == -1)
		return (-1);
	return (x + y);
}

int	ft_putstr(const char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return ((int) write(1, s, ft_strlen(s)));
}
