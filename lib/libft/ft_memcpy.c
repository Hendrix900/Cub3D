/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:06:46 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:07:10 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*l;
	const char		*q;

	l = (unsigned char *)dst;
	q = (const char *)src;
	if (l == NULL && q == NULL)
		return (0);
	while (n > 0)
	{
		*(l++) = *(q++);
		n--;
	}
	return (dst);
}
