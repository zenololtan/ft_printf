/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itoa_base16.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 15:20:22 by ztan           #+#    #+#                */
/*   Updated: 2020/01/28 15:43:56 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hex_len(unsigned long long num)
{
	unsigned long long	temp;
	int					len;

	temp = num;
	len = 0;
	if (num == 0)
		return (1);
	while (temp > 0)
	{
		temp = temp / 16;
		len++;
	}
	return (len);
}

char		*itoa_base16(unsigned long long num, char c)
{
	int		len;
	int		remainder;
	char	*ret;

	len = hex_len(num);
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len - 1 >= 0)
	{
		remainder = num % 16;
		num = num / 16;
		if (remainder < 10)
			ret[len - 1] = remainder + 48;
		else
		{
			if (c == 'x')
				ret[len - 1] = remainder + 87;
			else
				ret[len - 1] = remainder + 55;
		}
		len--;
	}
	return (ret);
}
