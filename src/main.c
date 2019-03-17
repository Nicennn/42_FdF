/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 19:17:13 by rcrestey          #+#    #+#             */
/*   Updated: 2019/03/16 21:23:42 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init(t_mlx *mlx)
{
	mlx->mv_x = 0;
	mlx->mv_y = -500;
	mlx->cent_x = 1000;
	mlx->cent_y = 1000;
	mlx->zoom = 2;
	mlx->alt = 2;
	mlx->proj = 1;
	mlx->img->size_x = 1920;
	mlx->img->size_y = 1920;
}

int		main(int ac, char **av)
{
	t_mlx	mlx;
	t_point	*points;
	t_img	img;

	if (ac != 2)
	{
		ft_putendl("Usage : ./fdf <filename>");
		return (1);
	}
	if (!(points = ft_checker(av[1])))
		return (1);
	mlx.img = &img;
	init(&mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 1080, "FdF");
	mlx.points = points;
	dessin(&mlx, points);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
			mlx.img->ptr, mlx.mv_x, mlx.mv_y);
	show_menu(mlx.mlx_ptr, mlx.win_ptr);
	mlx_key_hook(mlx.win_ptr, key_press, (void *)&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
