/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_unint.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 18:20:30 by ztan           #+#    #+#                */
/*   Updated: 2020/01/28 15:46:04 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	num_len_unsigned(unsigned int num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		num = num * -1;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static void	print_int(unsigned int num, t_format *list)
{
	char *str;
	char *temp;

	str = ft_itoa_unsigned(num);
	temp = str;
	print_str(str, list);
	free(temp);
}

static void	print_width(unsigned int num, int width,\
						int precision, t_format *list)
{
	int		len;
	char	padding;

	padding = ' ';
	len = num_len_unsigned(num);
	if (num == 0 && precision == -1)
		len = 0;
	if (len < precision)
		len = precision;
	if (list->zero_flag && !precision)
		padding = '0';
	if (!precision && list->minus_flag)
		print_int(num, list);
	while (width - len > 0)
	{
		print_char(padding, list);
		width -= 1;
	}
	if (!precision && !list->minus_flag)
		print_int(num, list);
}

static void	print_precision(unsigned int num, int precision, t_format *list)
{
	int len;

	len = num_len_unsigned(num);
	if (num == 0 && precision == -1)
		return ;
	if (len < precision)
	{
		precision -= len;
		while (precision > 0)
		{
			print_char('0', list);
			precision -= 1;
		}
	}
	print_int(num, list);
}

void		check_unint(va_list arguments, t_format *list)
{
	unsigned int		num;
	int					precision;
	int					width;

	precision = list->precision;
	width = list->width;
	num = va_arg(arguments, unsigned int);
	if (!precision && !width)
		print_int(num, list);
	if (!list->minus_flag && width)
		print_width(num, width, precision, list);
	if (precision)
		print_precision(num, precision, list);
	if (list->minus_flag && width)
		print_width(num, width, precision, list);
}
