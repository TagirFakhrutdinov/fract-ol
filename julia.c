/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 12:00:44 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:28:17 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(double x, double y, t_mlx *vars)
{
	double	zx;
	double	zy;
	int		iter;
	int		color;

	zx = find_x0(x, vars);
	zy = find_y0(y, vars);
	iter = find_iter_julia(zx, zy, vars);
	color = find_color(iter, vars);
	return (color);
}

int	find_iter_julia(double zx, double zy, t_mlx *vars)
{
	double	zx2;
	double	zy2;
	int		iter;

	iter = 0;
	zx2 = zx * zx;
	zy2 = zy * zy;
	while (zx2 + zy2 < 4 && ++iter < vars->fract.max_iter)
	{
		zy = (zx + zx) * zy + vars->fract.k_im;
		zx = zx2 - zy2 + vars->fract.k_re;
		zx2 = zx * zx;
		zy2 = zy * zy;
	}
	return (iter);
}
