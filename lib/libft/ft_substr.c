/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:03:04 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:10:34 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	cont;
	size_t	i;
	size_t	slen;

	cont = 0;
	i = start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (!str)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
	{
		str[cont] = '\0';
		return (str);
	}
	while (i < len + start)
		str[cont++] = s[i++];
	str[cont] = '\0';
	return (str);
}
