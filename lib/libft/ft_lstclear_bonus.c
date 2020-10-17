/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:52:00 by ccastill          #+#    #+#             */
/*   Updated: 2019/11/28 15:07:55 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *aux;
	t_list *tmp;

	aux = *lst;
	while (aux)
	{
		tmp = aux;
		del(aux->content);
		aux = aux->next;
		free(tmp);
	}
	*lst = NULL;
}
