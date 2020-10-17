/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:43:07 by ccastill          #+#    #+#             */
/*   Updated: 2019/11/15 13:26:46 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*q;
	unsigned char	*p;
	size_t			x;

	q = (unsigned char*)src;
	p = (unsigned char*)dest;
	x = 0;
	while (x < n)
	{
		p[x] = q[x];
		if (q[x] == (unsigned char)c)
			return ((void*)p + x + 1);
		x++;
	}
	return (NULL);
}
