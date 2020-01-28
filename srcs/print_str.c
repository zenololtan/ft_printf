/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 14:59:11 by ztan           #+#    #+#                */
/*   Updated: 2020/01/28 15:39:40 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_strlen(char *str, int len, t_format *list)
{
	int ret;

	ret = write(1, str, len);
	if (ret < 0)
		list->output = -1;
	if (list->output != -1)
		list->output += len;
}

static void	print_width(char *str, int width, int precision, t_format *list)
{
	char	padding;
	int		len;

	padding = ' ';
	len = ft_strlen(str);
	if (!precision && list->minus_flag)
		print_str(str, list);
	if (precision < len && precision != 0 && precision != -2)
	{
		len = precision;
		if (precision == -1)
			len = 0;
	}
	if (width > len)
	{
		if (list->zero_flag && !list->minus_flag)
			padding = '0';
		while (width - len > 0)
		{
			print_char(padding, list);
			width--;
		}
	}
	if (!precision && !list->minus_flag)
		print_str(str, list);
}

static void	print_precision(char *str, int precision, t_format *list)
{
	int len;

	len = ft_strlen(str);
	if (str[0] == '\0' || precision == -1)
		return ;
	if (precision < len && precision != -2)
		print_strlen(str, precision, list);
	else
		print_str(str, list);
}

void		check_str(va_list arguments, t_format *list)
{
	char	*str;
	int		precision;
	int		width;

	precision = list->precision;
	width = list->width;
	str = va_arg(arguments, char*);
	if (!str)
		str = "(null)";
	if (!precision && !width)
		print_str(str, list);
	if (!list->minus_flag && width)
		print_width(str, width, precision, list);
	if (precision)
		print_precision(str, precision, list);
	if (list->minus_flag && width)
		print_width(str, width, precision, list);
}
