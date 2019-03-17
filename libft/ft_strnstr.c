/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:46:57 by niogden           #+#    #+#             */
/*   Updated: 2018/11/13 22:30:22 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*ptr;

	ptr = (char *)haystack;
	if (len == 0)
		return (NULL);
	if (!(ft_strcmp(needle, "")))
		return ((char *)haystack);
	while (*haystack && ptr + (long)len - haystack >= (long)ft_strlen(needle))
	{
		if (!(ft_strncmp(haystack, needle, ft_strlen(needle))))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
