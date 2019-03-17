/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:50:30 by niogden           #+#    #+#             */
/*   Updated: 2018/11/14 06:09:31 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dest;

	size = ft_strlen(s1);
	if ((dest = (char *)malloc(sizeof(*dest) * (size + 1))) == 0)
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}
