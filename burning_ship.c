/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:34:22 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:27:40 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(double x, double y, t_mlx *vars)
{
	double	x0;
	double	y0;
	int		iter;
	int		color;

	x0 = find_x0(x, vars);
	y0 = find_y0(y, vars);
	iter = find_iter_ship(x0, y0, vars);
	color = find_color(iter, vars);
	return (color);
}

int	find_iter_ship(double x0, double y0, t_mlx *vars)
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
		zy = fabs((zx + zx) * zy) + y0;
		zx = zx2 - zy2 + x0;
		zx2 = zx * zx;
		zy2 = zy * zy;
	}
	return (iter);
}
