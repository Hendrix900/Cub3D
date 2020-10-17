/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:48:45 by ccastill          #+#    #+#             */
/*   Updated: 2019/12/04 17:38:42 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cont;

	cont = (char*)malloc(count * size);
	if (cont == 0)
		return (NULL);
	ft_bzero(cont, (count * size));
	return (cont);
}
