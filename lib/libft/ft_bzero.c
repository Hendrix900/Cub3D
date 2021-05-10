/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:36:45 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/10 22:17:40 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int				l;
	unsigned char	*q;

	q = (unsigned char *)s;
	l = 0;
	while (n > 0)
	{
		q[l] = 0;
		l++;
		n--;
	}
}
