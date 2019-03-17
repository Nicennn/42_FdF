/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 14:45:34 by niogden           #+#    #+#             */
/*   Updated: 2018/11/09 21:38:43 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	d;
	unsigned char	*e;

	d = (unsigned char)c;
	e = (unsigned char *)b;
	i = 0;
	while (i < len)
		e[i++] = d;
	return (b);
}
