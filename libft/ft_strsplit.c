/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:52:22 by niogden           #+#    #+#             */
/*   Updated: 2018/11/14 05:57:15 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strl(const char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c && str[i])
			j++;
		i++;
	}
	return (j);
}

static int		ft_counter(const char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			j++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s || !c)
		return (NULL);
	i = 0;
	k = 0;
	if (!(tab = (char **)malloc(sizeof(*tab) * (ft_counter(s, c) + 1))))
		return (NULL);
	while (i < ft_counter(s, c))
	{
		j = 0;
		if (!(tab[i] = (char *)malloc(sizeof(*tab) * (ft_strl(s, c) + 1))))
			return (NULL);
		while (s[k] == c && s[k])
			k++;
		while (s[k] != c && (s[k]))
			tab[i][j++] = s[k++];
		tab[i++][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
