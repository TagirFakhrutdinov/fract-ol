/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:53:08 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:28:41 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrote(double x, double y, t_mlx *vars)
{
	double	x0;
	double	y0;
	int		iter;
	int		color;

	x0 = find_x0(x, vars);
	y0 = find_y0(y, vars);
	iter = find_iter_mandel(x0, y0, vars);
	color = find_color(iter, vars);
	return (color);
}

int	find_iter_mandel(double x0, double y0, t_mlx *vars)
{
	double	zx;
	double	zy;
	double	zx2;
	double	zy2;
	int		iter;

	iter = 0;
	zx = 0.0;
	zy = 0.0;
	zx2 = 0.0;
	zy2 = 0.0;
	while (zx2 + zy2 < 4 && ++iter < vars->fract.max_iter)
	{
		zy = (zx + zx) * zy + y0;
		zx = zx2 - zy2 + x0;
		zx2 = zx * zx;
		zy2 = zy * zy;
	}
	return (iter);
}
