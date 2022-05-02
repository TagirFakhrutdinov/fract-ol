/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:06:31 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:28:33 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_mlx *vars)
{
	if (keycode == 53)
		close_win(vars);
	if (keycode == 15)
	{
		fractal_first_init(vars->fract.type, vars);
		draw_fractal(vars);
	}
	if (keycode == 8)
		change_color(vars);
	if (keycode == 11)
	{
		vars->block = !vars->block;
		printf("%d\n", vars->block);
	}
	if (keycode == 24 || keycode == 69 || keycode == 27 || keycode == 78)
		change_iterations(keycode, vars);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		move_img(keycode, vars);
	return (0);
}

int	close_win(t_mlx *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

void	change_color(t_mlx *vars)
{
	if (vars->fract.color == 2)
		vars->fract.color = 0;
	else
		vars->fract.color++;
	draw_fractal(vars);
}

void	change_iterations(int keycode, t_mlx *vars)
{
	if (keycode == 24 || keycode == 69)
		vars->fract.max_iter += 10;
	if (keycode == 27 || keycode == 78)
	{
		if (vars->fract.max_iter == 1)
			ft_putendl_fd("Iteration number: 1", 1);
		else if (vars->fract.max_iter <= 10)
			vars->fract.max_iter -= 1;
		else
			vars->fract.max_iter -= 10;
	}
	draw_fractal(vars);
}

void	move_img(int keycode, t_mlx *vars)
{
	if (keycode == 123)
	{
		vars->fract.re_min -= 0.1;
		vars->fract.re_max -= 0.1;
	}
	if (keycode == 124)
	{
		vars->fract.re_min += 0.1;
		vars->fract.re_max += 0.1;
	}
	if (keycode == 125)
	{
		vars->fract.im_min += 0.1;
		vars->fract.im_max += 0.1;
	}
	if (keycode == 126)
	{
		vars->fract.im_min -= 0.1;
		vars->fract.im_max -= 0.1;
	}
	draw_fractal(vars);
}
