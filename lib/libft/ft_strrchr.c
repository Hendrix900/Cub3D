/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 22:16:49 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:25:36 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_pos;

	last_pos = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			last_pos = s;
		s++;
	}
	if (last_pos)
		return ((char *)last_pos);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
