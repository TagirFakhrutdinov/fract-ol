/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:29:47 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:55:19 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	red_fr(double t)
{
	int	color;
	int	red;
	int	green;
	int	blue;

	red = (int)(15 * (1 - t) * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * 255);
	blue = (int)(15 * (1 - t) * t * t * 255);
	color = create_trgb(0, red, green, blue);
	return (color);
}

int	green_fr(double t)
{
	int	color;
	int	red;
	int	green;
	int	blue;

	red = (int)(15 * (1 - t) * t * t * 255);
	green = (int)(15 * (1 - t) * t * 255);
	blue = (int)(15 * (1 - t) * (1 - t) * t * 255);
	color = create_trgb(0, red, green, blue);
	return (color);
}

int	blue_fr(double t)
{
	int	color;
	int	red;
	int	green;
	int	blue;

	red = (int)(15 * (1 - t) * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(15 * (1 - t) * (1 - t) * t * 255);
	color = create_trgb(0, red, green, blue);
	return (color);
}

int	find_color(int iter, t_mlx *vars)
{
	double	t;
	int		color;

	t = (double)iter / (double)vars->fract.max_iter;
	if (vars->fract.color == 0)
		color = green_fr(t);
	if (vars->fract.color == 1)
		color = blue_fr(t);
	if (vars->fract.color == 2)
		color = red_fr(t);
	return (color);
}
