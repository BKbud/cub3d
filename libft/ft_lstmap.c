/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:27:29 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/10 14:47:09 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*node_front;

	if (!lst || !(*f))
		return (NULL);
	node = ft_lstnew((*f)(lst->content));
	if (!node)
		return (NULL);
	node_front = node;
	node = node->next;
	lst = lst->next;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&node_front, del);
			return (NULL);
		}
		ft_lstadd_back(&node_front, node);
		node = node->next;
		lst = lst->next;
	}
	return (node_front);
}
