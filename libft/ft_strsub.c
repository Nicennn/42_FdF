/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:35:58 by niogden           #+#    #+#             */
/*   Updated: 2018/11/11 14:06:59 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s)
	{
		if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
			return (NULL);
		ft_strncpy(str, s + start, len);
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
