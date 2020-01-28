/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 17:50:14 by ztan           #+#    #+#                */
/*   Updated: 2019/11/24 13:12:37 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *ar;

	ar = malloc(size * count);
	if (ar == NULL)
		return (NULL);
	ft_bzero(ar, size * count);
	return (ar);
}
