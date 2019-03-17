/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:44:33 by niogden           #+#    #+#             */
/*   Updated: 2018/11/12 23:35:54 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	temp;

	temp = ft_strlen(src) + size;
	if (size > ft_strlen(dst))
	{
		temp = ft_strlen(dst) + ft_strlen(src);
		ft_strncat(dst, (char *)src, size - ft_strlen(dst) - 1);
	}
	return (temp);
}
