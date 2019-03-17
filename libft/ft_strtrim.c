/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 23:08:29 by niogden           #+#    #+#             */
/*   Updated: 2018/11/14 04:19:20 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == 9 || s[i] == 10 || s[i] == 32) && s[i])
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[j] == 9 || s[j] == 10 || s[j] == 32)
		j--;
	return (ft_strsub(s, i, (j - i + 1)));
}
