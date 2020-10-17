/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:51:08 by ccastill          #+#    #+#             */
/*   Updated: 2019/11/28 15:02:21 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *aux;

	aux = *lst;
	if (aux == NULL)
		*lst = new;
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new;
		new->next = NULL;
	}
}
