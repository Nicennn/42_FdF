/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:05:15 by rcrestey          #+#    #+#             */
/*   Updated: 2019/03/16 22:14:06 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_ladd(t_lst **list, t_lst *new)
{
	if (!(*list))
	{
		new->next = (*list);
		(*list) = new;
	}
	else
	{
		while ((*list)->next)
			list = &(*list)->next;
		(*list)->next = new;
		new->next = NULL;
	}
}

t_lst	*ft_lnew(char **tab)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->tab = tab;
	new->next = NULL;
	return (new);
}

void	ft_padd(t_point **point, t_point *new)
{
	if (!(*point))
	{
		new->next = (*point);
		(*point) = new;
	}
	else
	{
		while ((*point)->next)
			point = &(*point)->next;
		(*point)->next = new;
		new->next = NULL;
	}
}

t_point	*ft_pnew(int x, int y, int z)
{
	t_point	*new;

	if (!(new = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	return (new);
}

void	ft_pfree(t_point *points)
{
	t_point	*tmp;

	while (points)
	{
		tmp = points;
		points = points->next;
		free(tmp);
	}
}
