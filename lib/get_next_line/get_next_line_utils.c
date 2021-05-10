/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:16:57 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/10 22:17:27 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//REVISADA POR NUEVA NORMINETTE V3

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	count;

	count = 0;
	if (!s)
		return (NULL);
	new = ((char *)malloc(sizeof(char) * len + 1));
	if (new == 0)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new[count] = '\0';
		return (new);
	}
	while (count < len)
		new[count++] = s[start++];
	new[count] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new;
	unsigned int	count;

	count = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	while (*s1 != '\0')
		new[count++] = *s1++;
	while (*s2 != '\0')
		new[count++] = *s2++;
	new[count] = '\0';
	return (new);
}

char	*ft_strdup(const char *src)
{
	char			*new;
	unsigned int	count;

	count = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!(new))
		return (NULL);
	while (src[count] != '\0')
	{
		new[count] = src[count];
		count++;
	}
	new[count] = '\0';
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
