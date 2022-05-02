/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:03:16 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:28:58 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	find_x0(double x, t_mlx *vars)
{
	double	x0;
	int		width;
	double	x_min;
	double	x_max;
	double	pixel_width;

	width = 1000;
	x_min = vars->fract.re_min;
	x_max = vars->fract.re_max;
	pixel_width = (x_max - x_min) / width;
	x0 = x_min + x * pixel_width;
	return (x0);
}

double	find_y0(double y, t_mlx *vars)
{
	double	y0;
	int		height;
	double	y_min;
	double	y_max;
	double	pixel_height;

	height = 1000;
	y_min = vars->fract.im_min;
	y_max = vars->fract.im_max;
	pixel_height = (y_max - y_min) / height;
	y0 = y_min + y * pixel_height;
	return (y0);
}
