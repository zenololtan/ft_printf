/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <ztan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/09 14:26:45 by ztan           #+#    #+#                */
/*   Updated: 2020/01/28 15:45:18 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_format
{
	char			specifier;
	int				zero_flag;
	int				minus_flag;
	int				width;
	int				precision;
	int				output;
}					t_format;

int					ft_printf(const char *format, ...);
int					format_check(char *format, \
					va_list arguments, t_format *list);
int					isspecifier(char format);
void				print_char(char s, t_format *list);
void				print_str(char *s, t_format *list);
char				*ft_itoa_unsigned(unsigned int n);
char				*itoa_base16(unsigned long long num, char c);
void				check_int(va_list arguments, t_format *list);
void				check_str(va_list arguments, t_format *list);
void				check_char(va_list arguments, t_format *list);
void				check_unint(va_list arguments, t_format *list);
void				check_hex(va_list arguments, t_format *list);
void				check_pointer(va_list arguments, t_format *list);

#endif
