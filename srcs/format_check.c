/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_check.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 13:31:56 by ztan           #+#    #+#                */
/*   Updated: 2020/01/28 15:48:12 by ztan          ########   odam.nl         */
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
	int			len;
	char		*temp;

	len = 0;
	format++;
	if (*format == '*')
	{
		len = va_arg(arguments, int);
		list->precision = len;
	}
	else
	{
		while (ft_isdigit(*format + len))
			len++;
		temp = malloc(sizeof(char) * len + 1);
		ft_strlcpy(temp, format, len + 1);
		list->precision = ft_atoi(temp);
		free(temp);
	}
	if (list->precision < 0)
		list->precision = -2;
	if (list->precision == 0)
		list->precision = -1;
}

static void	format_width(char *format, va_list arguments, t_format *list)
{
	int			len;
	char		*temp;

	len = 0;
	if (*format == '*')
	{
		len = va_arg(arguments, int);
		list->width = len;
	}
	else
	{
		while (ft_isdigit(*format + len))
			len++;
		temp = malloc(sizeof(char) * len + 1);
		ft_strlcpy(temp, format, len + 1);
		list->width = ft_atoi(temp);
		free(temp);
	}
	if (list->width < 0)
	{
		list->width = list->width * -1;
		list->minus_flag = 1;
	}
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
			format_precision(format + i, arguments, list);
		if (isspecifier(format[i]))
			format_specifier(format[i], list);
		i++;
	}
	if (list->minus_flag && list->zero_flag)
		list->zero_flag = 0;
	return (i);
}
