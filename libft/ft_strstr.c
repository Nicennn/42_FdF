/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:33:58 by niogden           #+#    #+#             */
/*   Updated: 2018/11/09 12:34:17 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str_copy;
	char	*find_copy;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			str_copy = (char *)haystack;
			find_copy = (char *)needle;
			while (*str_copy && *find_copy)
			{
				if (*str_copy != *find_copy)
					break ;
				str_copy++;
				find_copy++;
			}
			if (*find_copy == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (0);
}
