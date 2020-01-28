/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_pointer.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 20:21:10 by ztan           #+#    #+#                */
/*   Updated: 2020/01/28 15:39:37 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_width(char *hex, int width, int precision, t_format *list)
{
	int		len;
	char	padding;

	padding = ' ';
	len = ft_strlen(hex);
	if ((list->zero_flag && !list->precision) || list->minus_flag)
		print_str("0x", list);
	if (!precision && list->minus_flag)
		print_str(hex, list);
	if (ft_strncmp(hex, "0", 5) == 0 && precision == -1)
		len = 0;
	if (len < precision)
		len = precision;
	if (list->zero_flag && !precision)
		padding = '0';
	while (width - len > 0)
	{
		print_char(padding, list);
		width -= 1;
	}
	if (!list->zero_flag && !list->precision && !list->minus_flag)
		print_str("0x", list);
	if (!precision && !list->minus_flag)
		print_str(hex, list);
}

static void	print_precision(char *hex, int precision, t_format *list)
{
	int len;

	len = ft_strlen(hex);
	if (ft_strncmp(hex, "0", 5) == 0 && precision == -1)
	{
		print_str("0x", list);
		return ;
	}
	print_str("0x", list);
	if (len < precision)
	{
		precision -= len;
		while (precision > 0)
		{
			print_char('0', list);
			precision -= 1;
		}
	}
	print_str(hex, list);
}

void		check_pointer(va_list arguments, t_format *list)
{
	unsigned long long	num;
	int					precision;
	int					width;
	char				*hex;

	precision = list->precision;
	width = list->width - 2;
	num = (unsigned long long)va_arg(arguments, void *);
	hex = itoa_base16(num, 'x');
	if (!hex)
		list->output = -1;
	if (!precision && !width)
	{
		print_str("0x", list);
		print_str(hex, list);
	}
	if (!list->minus_flag && width)
		print_width(hex, width, precision, list);
	if (precision)
		print_precision(hex, precision, list);
	if (list->minus_flag && width)
		print_width(hex, width, precision, list);
	free(hex);
}
