/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:09:10 by psebasti          #+#    #+#             */
/*   Updated: 2017/06/27 14:37:00 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t		ft_fract_calc(t_setup *setup)
{
	printf("fract_calc f_mode %lu\n", setup->f_mode);
	//if (SETUP.f_mode == 0 || SETUP.f_mode == 3)
	//	if (ft_fractol_pthread(setup, 0, ft_mandelbrot) != 0)
	//		return (0);
	//if (SETUP.f_mode == 1 || SETUP.f_mode == 3)
	//	if (ft_fractol_pthread(setup, 1, ft_julia) != 0)
	//		return (0);
	return (1);
}

static void		ft_setup_fract_select(char **av, t_setup *setup)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		setup->f_mode = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		setup->f_mode = 1;
	else if (ft_strcmp(av[1], "burningship") == 0)
		setup->f_mode = 2;
	else if (ft_strcmp(av[1], "all") == 0)
		setup->f_mode = 3;
	printf("f_mode setup %lu\n", setup->f_mode);
}

int			main(int ac, char **av)
{
	t_setup	*setup = NULL;

	if (ac == 2)
	{
		setup = (t_setup *)malloc(sizeof(t_setup)); // 2
		if (!setup)
			return (-1);
		//ft_bzero(setup, sizeof(t_setup)); // 2
		setup->width = WIDTH;
		setup->height = HEIGHT;
		MLX = ft_initwindow("fractol", SETUP.width, SETUP.height);
		IMG = ft_imgnew(MLX->mlx_ptr, SETUP.width, SETUP.height);
		//ft_setup_fract_init(&SETUP);
		ft_setup_fract_select(av, setup);
		if (MLX && IMG)
			ft_mlx_process(setup);
		return (ft_setup_mode(av, setup, 0));
	}
	return (ft_error_usage());
}
