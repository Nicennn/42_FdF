/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 05:17:28 by niogden           #+#    #+#             */
/*   Updated: 2018/11/14 05:21:08 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		test_base(const char c)
{
	int		nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

int				ft_atoi_base(const char *str, int base)
{
	int		i;
	int		n;
	int		a;
	int		current;

	i = 0;
	n = 1;
	a = 0;
	if (ft_strcmp(str, "") == 0)
		return (0);
	while (str[i] > 0 && str[i] < 33 && str[i] != 27)
		i++;
	if (str[i] == 45)
		n = -n;
	if (str[i] == 43 || str[i] == 45)
		i++;
	current = test_base(str[i]);
	while (current >= 0 && current < base)
	{
		a = a * base + current;
		i++;
		current = test_base(str[i]);
	}
	return (a * n);
}
