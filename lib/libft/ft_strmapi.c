/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:03:43 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:26:23 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//REVISADA POR NUEVA NORMINETTE V3

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		l;

	l = 0;
	if (!s)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(new))
		return (NULL);
	while (s[l])
	{
		new[l] = f(l, s[l]);
		l++;
	}
	new[l] = '\0';
	return (new);
}
