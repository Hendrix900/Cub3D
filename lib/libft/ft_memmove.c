/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:52:02 by ccastill          #+#    #+#             */
/*   Updated: 2019/11/15 13:26:59 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *l;
	unsigned char *q;

	l = (unsigned char*)dest;
	q = (unsigned char*)src;
	if ((void*)l == NULL && (void*)q == NULL)
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
