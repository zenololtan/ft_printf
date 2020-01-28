/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 17:43:26 by ztan           #+#    #+#                */
/*   Updated: 2020/01/28 15:39:45 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			isspecifier(char format)
{
	if (format == 'c' || format == 's' || format == 'p' \
	|| format == 'i' || format == 'd' || format == 'u' \
	|| format == 'x' || format == 'X' || format == '%')
		return (1);
	return (0);
}

void		print_str(char *s, t_format *list)
{
	int ret;
	int len;

	len = ft_strlen(s);
	ret = write(1, s, len);
	if (ret < 0)
		list->output = -1;
	if (list->output != -1)
		list->output += len;
}

void		print_char(char s, t_format *list)
{
	int ret;

	ret = write(1, &s, 1);
	if (ret < 0)
		list->output = -1;
	if (list->output != -1)
		list->output += 1;
}

static char	*put_num(unsigned int n, int count, char *ret)
{
	int	i;

	i = 0;
	ret[count] = '\0';
	if (n == 0)
		ret[i] = '0';
	while (n > 0)
	{
		ret[count - 1] = (n % 10) + '0';
		n /= 10;
		count--;
	}
	return (ret);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char			*ret;
	unsigned int	temp;
	int				count;

	count = 0;
	temp = n;
	if (temp == 0)
		count = 1;
	if (temp < 0)
		count++;
	while (temp != 0)
	{
		count++;
		temp = temp / 10;
	}
	ret = malloc(sizeof(char) * (count + 1));
	if (ret == NULL)
		return (NULL);
	return (put_num(n, count, ret));
}
