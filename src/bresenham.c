/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 11:28:13 by rcrestey          #+#    #+#             */
/*   Updated: 2019/03/16 19:05:55 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		bresenham(t_mlx *mlx, t_point p0, t_point *p1)
{
	int		d[4];
	int		error;
	int		e2;

	d[0] = abs(p1->xn - p0.xn);
	d[1] = p0.xn < p1->xn ? 1 : -1;
	d[2] = abs(p1->yn - p0.yn);
	d[3] = p0.yn < p1->yn ? 1 : -1;
	error = (d[0] > d[2] ? d[0] : -d[2]) / 2;
	while (p0.xn != p1->xn || p0.yn != p1->yn)
	{
		mlx->img->data[p0.yn * mlx->img->size_x + p0.xn] =
			0xffffff - (p0.z * 50000);
		e2 = error;
		if (e2 > -d[0])
		{
			error -= d[2];
			p0.xn += d[1];
		}
		if (e2 < d[2])
		{
			error += d[0];
			p0.yn += d[3];
		}
	}
}
