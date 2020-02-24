/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:31:56 by ztan           #+#    #+#                */
/*   Updated: 2020/02/05 13:19:39 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	format_specifier(char format, t_format *list)
{
	if (format == '%')
		list->specifier = '%';
	if (format == 'c')
		list->specifier = 'c';
	if (format == 's')
		list->specifier = 's';
	if (format == 'p')
		list->specifier = 'p';
	if (format == 'i')
		list->specifier = 'i';
	if (format == 'd')
		list->specifier = 'd';
	if (format == 'u')
		list->specifier = 'u';
	if (format == 'x')
		list->specifier = 'x';
	if (format == 'X')
		list->specifier = 'X';
}

static void	format_precision(char *format, va_list arguments, t_format *list)
{
	if (*format == '*')
		list->precision = va_arg(arguments, int);
	else
		list->precision = ft_atoi(format);
	if (list->precision < 0)
		list->precision = -2;
	if (list->precision == 0)
		list->precision = -1;
}

static void	format_width(char *format, va_list arguments, t_format *list)
{
	if (*format == '*')
		list->width = va_arg(arguments, int);
	else
		list->width = ft_atoi(format);
	if (list->width < 0)
		list->minus_flag = 1;
	if (list->width < 0)
		list->width = list->width * -1;
}

static void	format_flag(char format, t_format *list)
{
	if (format == '0')
		list->zero_flag = 1;
	else
		list->minus_flag = 1;
}

int			format_check(char *format, va_list arguments, t_format *list)
{
	int i;

	i = 0;
	while (list->specifier == 0)
	{
		if ((format[i] == '0' || format[i] == '-') && \
						!list->width && !list->precision)
			format_flag(format[i], list);
		if ((format[i] == '*' || ft_isdigit(format[i])) && \
							!list->width && !list->precision)
			format_width(format + i, arguments, list);
		if (format[i] == '.')
			format_precision(format + 1 + i, arguments, list);
		if (isspecifier(format[i]))
			format_specifier(format[i], list);
		i++;
	}
	if (list->minus_flag && list->zero_flag)
		list->zero_flag = 0;
	return (i);
}
