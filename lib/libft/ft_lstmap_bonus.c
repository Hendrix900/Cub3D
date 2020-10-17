/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:20 by ccastill          #+#    #+#             */
/*   Updated: 2019/11/28 15:08:36 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *aux;

	if (!lst)
		return (NULL);
	aux = ft_lstnew(f(lst->content));
	new = aux;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(aux->next = ft_lstnew(f(lst->content))))
		{
			del(aux->next);
			free(aux->next);
			return (NULL);
		}
		aux = aux->next;
	}
	return (new);
}
