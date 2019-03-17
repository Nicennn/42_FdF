/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:08:30 by niogden           #+#    #+#             */
/*   Updated: 2018/11/11 18:03:21 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_counter(int n)
{
	int		i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		ft_negative(int n, int i, char *str)
{
	n = -n;
	str[0] = '-';
	while (i)
	{
		str[i--] = n % 10 + 48;
		n = n / 10;
	}
}

char			*ft_itoa(int n)
{
	int		i;
	char	*str;

	i = ft_counter(n);
	if (!(str = (char *)malloc(sizeof(*str) * i + 1)))
		return (NULL);
	str[i--] = '\0';
	if (n == -2147483648)
	{
		str[i--] = '8';
		n = -214748364;
	}
	if (n < 0)
	{
		ft_negative(n, i, str);
		return (str);
	}
	while (i >= 0)
	{
		str[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
