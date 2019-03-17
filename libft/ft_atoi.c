/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:52:35 by niogden           #+#    #+#             */
/*   Updated: 2018/11/13 23:39:59 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		a;
	int		n;

	i = 0;
	a = 0;
	n = 1;
	if (ft_strcmp(str, "") == 0)
		return (0);
	while (str[i] > 0 && str[i] < 33 && str[i] != 27)
		i++;
	if (str[i] == 45)
		n = -n;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] > 47 && str[i] < 58)
		a = a * 10 + str[i++] - 48;
	return (a * n);
}
