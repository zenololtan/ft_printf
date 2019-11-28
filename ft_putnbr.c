/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 19:23:00 by ztan           #+#    #+#                */
/*   Updated: 2019/11/27 16:13:57 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_putnbr(int n)
{
	int int_min;

	int_min = -2147483648;
	if (n == int_min)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n % 10 + '0');
}
