/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ztan <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:02:18 by ztan           #+#    #+#                */
/*   Updated: 2019/11/14 18:56:41 by ztan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	int val;

	val = c;
	if (c >= 'A' && c <= 'Z')
		val += ('a' - 'A');
	return (val);
}
