/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 10:21:08 by ztan           #+#    #+#                */
/*   Updated: 2019/11/27 15:45:55 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		while (n != i)
		{
			((char *)dst)[i] = ((const char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n != 0)
		{
			n--;
			((char *)dst)[n] = ((const char *)src)[n];
		}
	}
	return (dst);
}
