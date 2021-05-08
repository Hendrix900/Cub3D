/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:22:20 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:23:50 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*q;
	size_t			l;

	q = (unsigned char *)s;
	l = 0;
	while (++l <= n)
		if (*(q++) == (unsigned char)c)
			return ((void *)--q);
	return (0);
}
