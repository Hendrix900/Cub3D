/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:03:43 by ccastill          #+#    #+#             */
/*   Updated: 2019/11/25 12:59:35 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		l;

	l = 0;
	if (!s)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[l])
	{
		new[l] = f(l, s[l]);
		l++;
	}
	new[l] = '\0';
	return (new);
}
