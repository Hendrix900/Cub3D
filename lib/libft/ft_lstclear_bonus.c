/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 23:52:00 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:20:18 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*tmp;

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
