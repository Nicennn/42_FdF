/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 11:19:48 by rcrestey          #+#    #+#             */
/*   Updated: 2019/03/16 22:34:06 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "math.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef	struct		s_lst
{
	char			**tab;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				xn;
	int				yn;
	struct s_point	*next;
}					t_point;

typedef struct		s_img
{
	void			*ptr;
	int				*data;
	int				size_x;
	int				size_y;
	int				bpp;
	int				size;
	int				endian;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				zoom;
	int				mv_x;
	int				mv_y;
	int				cent_x;
	int				cent_y;
	int				proj;
	float			alt;
	t_img			*img;
	t_point			*points;
}					t_mlx;

int					key_press(int key, t_mlx *mlx);
void				init(t_mlx	*mlx);
void				ft_pfree(t_point *points);
void				ft_ladd(t_lst **list, t_lst *new);
void				ft_padd(t_point **point, t_point *new);
void				bresenham(t_mlx *mlx, t_point p0, t_point *p1);
void				dessin(t_mlx *mlx, t_point *points);
void				show_menu(void *mlx_ptr, void *win_ptr);
t_lst				*ft_lnew(char **tab);
t_point				*ft_pnew(int x, int y, int z);
t_point				*ft_checker(char *file);
#endif
