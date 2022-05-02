/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:52:05 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:46:05 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct s_fract {
	int		type;
	int		color;
	int		max_iter;
	double	re_min;
	double	re_max;
	double	im_min;
	double	im_max;
	double	k_re;
	double	k_im;
}				t_fract;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	t_img	img;
	t_fract	fract;
	int		block;
}				t_mlx;

/*draw.c*/
int		draw_window(int flag);
void	fractal_first_init(int flag, t_mlx *vars);
void	draw_fractal(t_mlx *vars);

/*mandelbrote.c*/
int		mandelbrote(double x, double y, t_mlx *vars);
int		find_iter_mandel(double x0, double y0, t_mlx *vars);

/*julia.c*/
int		julia(double x, double y, t_mlx *vars);
int		find_iter_julia(double zx, double zy, t_mlx *vars);

/*burning_ship.c*/
int		burning_ship(double x, double y, t_mlx *vars);
int		find_iter_ship(double x0, double y0, t_mlx *vars);

/*utils.c*/
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
double	find_x0(double x, t_mlx *vars);
double	find_y0(double y, t_mlx *vars);

/*key_hooks.c*/
int		key_hook(int keycode, t_mlx *vars);
int		close_win(t_mlx *vars);
void	change_color(t_mlx *vars);
void	change_iterations(int keycode, t_mlx *vars);
void	move_img(int keycode, t_mlx *vars);

/*mouse_hooks.c*/
int		mouse_hook(int code, t_mlx *vars);
int		zoom(int keycode, int x, int y, t_mlx *vars);
int		julia_motion(int x, int y, t_mlx *vars);

/*colors.c*/
int		create_trgb(int t, int r, int g, int b);
int		find_color(int iter, t_mlx *vars);
int		red_fr(double t);
int		green_fr(double t);
int		blue_fr(double t);

#endif
