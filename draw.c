/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:43:32 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:28:13 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_mlx *vars)
{
	int		x;
	int		y;
	int		color;

	vars->img.img = mlx_new_image(vars->mlx, 1000, 1000);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	x = 0;
	while (x != 1000)
	{
		y = 0;
		while (y != 1000)
		{
			if (vars->fract.type == 0)
				color = julia(x, y, vars);
			if (vars->fract.type == 1)
				color = mandelbrote(x, y, vars);
			if (vars->fract.type == 2)
				color = burning_ship(x, y, vars);
			my_mlx_pixel_put(&vars->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	fractal_first_init(int flag, t_mlx *vars)
{
	vars->fract.color = 0;
	vars->fract.type = flag;
	vars->fract.max_iter = 100;
	vars->fract.re_max = 2.0;
	vars->fract.re_min = -2.0;
	vars->fract.im_max = 2.0;
	vars->fract.im_min = -2.0;
	vars->fract.k_re = -0.7;
	vars->fract.k_im = 0.27015;
}

int	draw_window(int flag)
{
	t_mlx	vars;

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (-1);
	vars.win = mlx_new_window(vars.mlx, 1000, 1000, "fract-ol");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (-1);
	}
	vars.block = 0;
	fractal_first_init(flag, &vars);
	draw_fractal(&vars);
	mlx_hook(vars.win, 2, 0, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, close_win, &vars);
	mlx_hook(vars.win, 4, 0, zoom, &vars);
	if (vars.fract.type == 0 && vars.block == 0)
		mlx_hook(vars.win, 6, 0, julia_motion, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_image(vars.mlx, vars.img.img);
	free(vars.mlx);
	return (0);
}
