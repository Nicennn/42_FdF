/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:30:17 by niogden           #+#    #+#             */
/*   Updated: 2019/03/16 17:20:45 by niogden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		show_menu(void *mlx_ptr, void *win_ptr)
{
	int		y;
	int		color;

	y = 300;
	color = 0xDFDAD6;
	mlx_string_put(mlx_ptr, win_ptr, 75, y += 20, 0xE60000, "Controls");
	mlx_string_put(mlx_ptr, win_ptr, 75, y += 5, 0xE60000, "________");
	mlx_string_put(mlx_ptr, win_ptr, 25, y += 30, color, "Zoom: + or -");
	mlx_string_put(mlx_ptr, win_ptr, 25, y += 25, color, "Move: Arrows");
	mlx_string_put(mlx_ptr, win_ptr, 25, y += 25, color,
			"Change height: W or S");
	mlx_string_put(mlx_ptr, win_ptr, 25, y += 25, color, "Reset: R");
	mlx_string_put(mlx_ptr, win_ptr, 25, y += 25, color, "Change view: V");
}

static void	show(t_mlx *mlx)
{
	mlx->zoom = (mlx->zoom < 1 ? 1 : mlx->zoom);
	mlx->zoom = (mlx->zoom > 7 ? 7 : mlx->zoom);
	mlx->alt = (mlx->alt < -3 ? -3 : mlx->alt);
	mlx->alt = (mlx->alt > 3 ? 3 : mlx->alt);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr,
			mlx->win_ptr, mlx->img->ptr, mlx->mv_x, mlx->mv_y);
	show_menu(mlx->mlx_ptr, mlx->win_ptr);
}

int			key_press(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		ft_pfree(mlx->points);
		exit(0);
	}
	if (key == 123 || key == 124)
		mlx->mv_x += (key == 123 ? -30 : 30);
	else if (key == 125 || key == 126)
		mlx->mv_y += (key == 126 ? -30 : 30);
	else
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img->ptr);
		if (key == 24 || key == 27)
			mlx->zoom += (key == 27 ? -1 : 1);
		if (key == 1 || key == 13)
			mlx->alt += (key == 1 ? -0.5 : 0.5);
		if (key == 9)
			mlx->proj = (mlx->proj ? 0 : 1);
		if (key == 15)
			init(mlx);
		dessin(mlx, mlx->points);
	}
	show(mlx);
	return (0);
}
