/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:53:20 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:27:41 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//REVISADA POR NUEVA NORMINETTE V3

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;

	if (!lst)
		return (NULL);
	aux = ft_lstnew(f(lst->content));
	new = aux;
	while (lst->next != NULL)
	{
		lst = lst->next;
		aux->next = ft_lstnew(f(lst->content));
		if (!(aux->next))
		{
			del(aux->next);
			free(aux->next);
			return (NULL);
		}
		aux = aux->next;
	}
	return (new);
}
