/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:06:04 by ztan           #+#    #+#                */
/*   Updated: 2019/11/27 15:46:54 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*knee;
	size_t	i;
	size_t	j;

	i = 0;
	hay = (char *)haystack;
	knee = (char *)needle;
	if (knee[0] == '\0')
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		j = 0;
		while (hay[i] == knee[j] && i < len)
		{
			i++;
			j++;
			if (knee[j] == '\0')
				return (hay + (i - j));
		}
		i++;
	}
	return (0);
}
