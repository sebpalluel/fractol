/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:09:10 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/12 15:11:38 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_error_usage(void)
{
	ft_putendl("Usage:\n\
			./fractol \"mandelbrot\"\n\
			./fractol \"julia\"\n\
			./fractol \"burningship\"\n\
			./fractol \"cantor\"\n\
			./fractol \"all\"");
	return (0);
}

size_t			ft_fract_calc(t_setup *setup)
{
	if (SETUP.f_mode == 0 || SETUP.f_mode == 4)
		if (ft_fractol_pthread(setup, 0, ft_mandelbrot) != 0)
			return (OK);
	if (SETUP.f_mode == 1 || SETUP.f_mode == 4)
		if (ft_fractol_pthread(setup, 1, ft_julia) != 0)
			return (OK);
	if (SETUP.f_mode == 2 || SETUP.f_mode == 4)
		if (ft_fractol_pthread(setup, 2, ft_burningship) != 0)
			return (OK);
	if (SETUP.f_mode == 3)
		if (ft_fractol_pthread(setup, 3, ft_cantor) != 0)
			return (OK);
	return (ERROR);
}

void			ft_setup_f_mode(size_t trigger, t_setup *setup)
{
	if (!trigger)
	{
		if (setup->f_mode == 0 || setup->f_mode == 4)
			ft_mandelbrot_init(setup);
		if (setup->f_mode == 1 || setup->f_mode == 4)
			ft_julia_init(setup);
		if (setup->f_mode == 2 || setup->f_mode == 4)
			ft_burningship_init(setup);
		if (setup->f_mode == 3 || setup->f_mode == 4)
			ft_cantor_init(setup);
	}
	else
	{
		ft_mandelbrot_init(setup);
		ft_julia_init(setup);
		ft_burningship_init(setup);
		ft_cantor_init(setup);
	}
}

static size_t	ft_setup_fract_select(char **av, t_setup *setup)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		setup->f_mode = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		setup->f_mode = 1;
	else if (ft_strcmp(av[1], "burningship") == 0)
		setup->f_mode = 2;
	else if (ft_strcmp(av[1], "cantor") == 0)
		setup->f_mode = 3;
	else if (ft_strcmp(av[1], "all") == 0)
		setup->f_mode = 4;
	ft_setup_f_mode(1, &SETUP);
	return (ft_fract_calc(setup));
}

int				main(int ac, char **av)
{
	t_setup	*setup;

	if (ac == 2)
	{
		setup = (t_setup *)malloc(sizeof(t_setup) * (NUM_THREAD + 1));
		if (!setup)
			return (-1);
		ft_bzero(setup, sizeof(t_setup) * (NUM_THREAD + 1));
		if (ft_setup_mode(setup, 1) != OK && \
				ft_setup_fract_select(av, setup) != OK && \
				SETUP.f_mode != 666)
			ft_mlx_process(setup);
		return (ft_setup_mode(setup, 0));
	}
	return (ft_error_usage());
}
