/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kflorett <kflorett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:17:36 by kflorett          #+#    #+#             */
/*   Updated: 2022/03/06 15:28:37 by kflorett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_help(void)
{
	ft_putendl_fd("Чтобы сменить цвет нажми клавишу 'c'", 1);
	ft_putendl_fd("Для увеличения числа итераций нажми '+'", 1);
	ft_putendl_fd("Для уменьшения числа итераций нажми '-'", 1);
	ft_putendl_fd("Чтобы вернуть рисунок в начальное состояние нажми 'r'", 1);
	ft_putendl_fd("Передвижение стрелками", 1);
	ft_putendl_fd("Приближение колесом мыши", 1);
	ft_putendl_fd("Чтобы заблокировать фрактал Жюлиа нажми 'b'", 1);
	ft_putendl_fd("Для выхода нажми ESC или на крестик", 1);
}

int	main(int argc, char **argv)
{
	int	flag;

	if (argc < 2)
	{
		ft_putendl_fd("No arguments!", 1);
		ft_putendl_fd("Print 'Mandelbrote', 'Julia' or 'Ship'", 1);
		return (-1);
	}
	if ((ft_strncmp(argv[1], "Mandelbrote", 11)
			&& ft_strncmp(argv[1], "Julia", 5)
			&& ft_strncmp(argv[1], "Ship", 4)) != 0)
	{
		ft_putendl_fd("Wrong arguments!", 1);
		ft_putendl_fd("Print 'Mandelbrote', 'Julia' or 'Ship'", 1);
		return (-1);
	}
	flag = 0;
	if (ft_strncmp(argv[1], "Mandelbrote", 11) == 0)
		flag = 1;
	if (ft_strncmp(argv[1], "Ship", 6) == 0)
		flag = 2;
	print_help();
	if (draw_window(flag) == -1)
		return (-1);
	return (0);
}
