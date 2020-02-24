/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 13:55:41 by ztan           #+#    #+#                */
/*   Updated: 2020/01/31 17:15:53 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		set_struct(t_format *list)
{
	list->specifier = 0;
	list->zero_flag = 0;
	list->minus_flag = 0;
	list->width = 0;
	list->precision = 0;
}

static void	scan_specifier(va_list arguments, t_format *list)
{
	if (list->specifier == 'c' || list->specifier == '%')
		check_char(arguments, list);
	if (list->specifier == 's')
		check_str(arguments, list);
	if (list->specifier == 'p')
		check_pointer(arguments, list);
	if (list->specifier == 'i' || list->specifier == 'd')
		check_int(arguments, list);
	if (list->specifier == 'u')
		check_unint(arguments, list);
	if (list->specifier == 'x' || list->specifier == 'X')
		check_hex(arguments, list);
}

int			ft_printf(const char *format, ...)
{
	va_list		arguments;
	t_format	list;

	va_start(arguments, format);
	list.output = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			set_struct(&list);
			format += format_check((char*)format, arguments, &list);
			scan_specifier(arguments, &list);
		}
		else
		{
			print_char(*format, &list);
			format++;
		}
		if (list.output == -1)
			break ;
	}
	va_end(arguments);
	return (list.output);
}
