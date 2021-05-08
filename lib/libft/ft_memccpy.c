/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:43:07 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:11:55 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*q;
	unsigned char	*p;
	size_t			x;

	q = (unsigned char *)src;
	p = (unsigned char *)dest;
	x = 0;
	while (x < n)
	{
		p[x] = q[x];
		if (q[x] == (unsigned char)c)
			return ((void *)p + x + 1);
		x++;
	}
	return (NULL);
}
