/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:22:04 by niogden           #+#    #+#             */
/*   Updated: 2018/11/13 18:16:45 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstaddend(t_list **lst2, t_list *new)
{
	if (!(*lst2))
		ft_lstadd(lst2, new);
	else
	{
		while ((*lst2)->next)
			lst2 = &(*lst2)->next;
		(*lst2)->next = new;
		new->next = NULL;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;

	if (!(lst2 = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		ft_lstaddend(&lst2, (f)(lst));
		lst = lst->next;
	}
	return (lst2);
}
