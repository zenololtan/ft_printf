/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:30:56 by ztan           #+#    #+#                */
/*   Updated: 2019/11/24 13:56:03 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ed;

	i = 0;
	ed = b;
	while (i < len)
	{
		ed[i] = c;
		i++;
	}
	return (b);
}
