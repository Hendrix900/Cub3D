/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:52:02 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:23:24 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*l;
	unsigned char	*q;

	l = (unsigned char *)dest;
	q = (unsigned char *)src;
	if ((void *)l == NULL && (void *)q == NULL)
		return (NULL);
	if (l < q)
	{
		while (n--)
		{
			*(l++) = *(q++);
		}
		return (dest);
	}
	else
	{
		while (n--)
			l[n] = q[n];
	}
	return (dest);
}
