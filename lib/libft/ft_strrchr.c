/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 22:16:49 by ccastill          #+#    #+#             */
/*   Updated: 2020/01/25 05:16:50 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *last_pos;

	last_pos = NULL;
	while (*s != '\0')
	{
		if (*s == c) 
			last_pos = s;
		s++;
	}
	if (last_pos)
		return ((char*)last_pos);
	if (c == '\0')
		return ((char*)s);
	return (NULL);
}
