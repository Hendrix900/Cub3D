/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:24:12 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:14:04 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*q;
	unsigned char	*p;
	size_t			l;

	q = (unsigned char *)s1;
	p = (unsigned char *)s2;
	l = 0;
	if (n == 0)
		return (0);
	while (*q == *p && ++l < n)
	{
		q++;
		p++;
	}
	return ((int)(*q - *p));
}
