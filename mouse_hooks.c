/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:43:33 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:28:52 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	interpolate(double start, double end, double interpolate)
{
	return (start + ((end - start) * interpolate));
}

int	zoom(int keycode, int x, int y, t_mlx *vars)
{
	double	mouse_re;
	double	mouse_im;
	double	interpolation;

	if (keycode == 4 || keycode == 5)
	{
		mouse_re = (double)x / (1000 / (vars->fract.re_max
					- vars->fract.re_min)) + vars->fract.re_min;
		mouse_im = (double)y / (1000 / (vars->fract.im_max
					- vars->fract.im_min)) + vars->fract.im_min;
		interpolation = 0.9;
		if (keycode == 5)
			interpolation = 1.1;
		vars->fract.re_min = interpolate(mouse_re,
				vars->fract.re_min, interpolation);
		vars->fract.re_max = interpolate(mouse_re,
				vars->fract.re_max, interpolation);
		vars->fract.im_min = interpolate(mouse_im,
				vars->fract.im_min, interpolation);
		vars->fract.im_max = interpolate(mouse_im,
				vars->fract.im_max, interpolation);
		draw_fractal(vars);
	}
	return (0);
}

int	julia_motion(int x, int y, t_mlx *vars)
{
	if (vars->block == 0)
	{
		vars->fract.k_re = (4 * ((double)x / 1000 - 0.5));
		vars->fract.k_im = (4 * ((double)(1000 - y) / 1000 - 0.5));
		draw_fractal(vars);
	}
	return (0);
}
