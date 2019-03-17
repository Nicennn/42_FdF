/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dessin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 19:35:26 by rcrestey          #+#    #+#             */
/*   Updated: 2019/03/16 19:05:43 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	calculvue(t_mlx mlx, t_point *points)
{
	while (points)
	{
		if (mlx.proj)
		{
			points->xn = ((points->x - points->y) * cos(0.523599))
				* mlx.zoom + mlx.cent_x;
			points->yn = (-(points->z * mlx.alt) + (points->x + points->y)
					* sin(0.523599)) * mlx.zoom + mlx.cent_y;
		}
		else
		{
			points->xn = (points->x - points->y) * mlx.zoom + mlx.cent_x;
			points->yn = (-(points->z * mlx.alt) + (points->x + points->y))
				* mlx.zoom + mlx.cent_y;
		}
		points = points->next;
	}
}

static void	tracex(t_mlx *mlx, t_point *points)
{
	while (points)
	{
		if (points->next && points->y == points->next->y)
			bresenham(mlx, *points, points->next);
		points = points->next;
	}
}

static void	tracey(t_mlx *mlx, t_point *points)
{
	t_point	*swap;
	t_point *temps;

	temps = points;
	while (points)
	{
		swap = points;
		while (temps)
		{
			if (temps->x == points->x && temps->y != points->y)
			{
				bresenham(mlx, *swap, temps);
				swap = temps;
			}
			temps = temps->next;
		}
		points = points->next;
		temps = points;
		if (points->x == 0)
			break ;
	}
}

void		dessin(t_mlx *mlx, t_point *points)
{
	t_point		*tmp;

	tmp = points;
	calculvue(*mlx, tmp);
	while (tmp)
	{
		mlx->img->size_x = (mlx->img->size_x < tmp->xn ? tmp->xn + 300
				: mlx->img->size_x);
		mlx->img->size_y = (mlx->img->size_y < tmp->yn ? tmp->yn + 300
				: mlx->img->size_y);
		mlx->img->size_y = (tmp->yn < 20 ? mlx->img->size_y + 100
				: mlx->img->size_y);
		mlx->cent_y = (tmp->yn < 20 ? mlx->cent_y + 100 : mlx->cent_y);
		tmp = tmp->next;
	}
	calculvue(*mlx, points);
	mlx->img->ptr = mlx_new_image(mlx->mlx_ptr, mlx->img->size_x,
			mlx->img->size_y);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->ptr, &(mlx->img->bpp),
			&(mlx->img->size), &(mlx->img->endian));
	tracex(mlx, points);
	tracey(mlx, points);
}
