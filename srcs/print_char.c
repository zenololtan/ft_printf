/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 17:24:40 by ztan           #+#    #+#                */
/*   Updated: 2020/01/28 15:39:28 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	print_width(int width, t_format *list)
{
	char	padding;

	padding = ' ';
	if (list->zero_flag && !list->minus_flag)
		padding = '0';
	width -= 1;
	while (width > 0)
	{
		print_char(padding, list);
		width--;
	}
}

void		check_char(va_list arguments, t_format *list)
{
	char	chr;
	int		width;

	width = list->width;
	if (list->specifier == '%')
		chr = '%';
	else
		chr = va_arg(arguments, int);
	if (!list->minus_flag && width)
		print_width(width, list);
	print_char(chr, list);
	if (list->minus_flag && width)
		print_width(width, list);
}
