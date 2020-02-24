/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_int.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 16:16:18 by ztan           #+#    #+#                */
/*   Updated: 2020/02/14 17:33:16 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			num_len(int num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	if (num == -2147483648)
		return (10);
	if (num < 0)
		num = num * -1;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static void	print_int(int num, int precision, t_format *list)
{
	char *str;
	char *temp;

	if (num == -2147483648)
	{
		if (!precision)
			str = ft_strdup("-2147483648");
		else
			str = ft_strdup("2147483648");
	}
    else
        str = ft_itoa(num);
	temp = str;
	if (num < 0 && list->zero_flag && num_len(num) < list->width)
		str++;
	print_str(str, list);
	free(temp);
}

static void	print_width(int num, int width, int precision, t_format *list)
{
	int		len;
	char	padding;

	padding = ' ';
	len = num_len(num);
	if (num == 0 && precision == -1)
		len = 0;
	if (len < precision)
		len = precision;
	if (num < 0)
		len++;
	if (list->zero_flag && (!precision || precision == -2))
		padding = '0';
	if (!precision && list->zero_flag && num < 0 && len <= width)
		print_char('-', list);
	if (!precision && list->minus_flag)
		print_int(num, precision, list);
	while (width - len > 0)
	{
		print_char(padding, list);
		width -= 1;
	}
	if (!precision && !list->minus_flag)
		print_int(num, precision, list);
}

static void	print_precision(int num, int precision, t_format *list)
{
	int len;

	len = num_len(num);
	if (num == 0 && precision == -1)
		return ;
	if (num < 0)
	{
		print_char('-', list);
		if (num != -2147483648)
			num = num * -1;
	}
	if (len < precision)
	{
		precision -= len;
		while (precision > 0)
		{
			print_char('0', list);
			precision -= 1;
		}
	}
	print_int(num, precision, list);
}

void		check_int(va_list arguments, t_format *list)
{
	int		num;
	int		precision;
	int		width;

	precision = list->precision;
	width = list->width;
	num = va_arg(arguments, int);
	if (!precision && !width)
		print_int(num, precision, list);
	if (!list->minus_flag && width)
		print_width(num, width, precision, list);
	if (precision)
		print_precision(num, precision, list);
	if (list->minus_flag && width)
		print_width(num, width, precision, list);
}
