/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:58:45 by psebasti          #+#    #+#             */
/*   Updated: 2017/04/14 18:54:30 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static size_t	ft_setup_fract_init(t_setup *setup)
{
	if (setup->fract == 0 || setup->fract == 3)
		ft_mandelbrot_init(setup);
	if (setup->fract == 1 || setup->fract == 3)
		ft_julia_init(setup);
	if (setup->fract == 2 || setup->fract == 3)
		ft_burningship_init(setup);
	return (1);
}

size_t			ft_setup_init(t_setup *setup)
{
	MLX = ft_initwindow("fractol", setup->width, setup->height);
	IMG = ft_imgnew(MLX->mlx_ptr, setup->width, setup->height);
	if (MLX && IMG && ft_setup_fract_init(setup))
	{
		ft_fract_calc(setup);
		return (1);
	}
	return (0);
}

static void		ft_setup_delete(t_setup *setup)
{

}

static void		ft_setup_fract_select(char **av, t_setup *setup)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		setup->fract = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		setup->fract = 1;
	else if (ft_strcmp(av[1], "burningship") == 0)
		setup->fract = 2;
	else if (ft_strcmp(av[1], "all") == 0)
		setup->fract = 3;
}

size_t			ft_setup_mode(int ac, char **av, t_setup *setup, size_t mode)
{
	if (mode)
	{
		setup->fract = 666;
		if (ac == 2)
			ft_setup_fract_select(av, setup);
		if (setup->fract == 666)
		{
			ft_putendl("Usage /fractol \"mandelbrot\", \"julia\", \"burningship\"");
			return (0);
		}
		return (1);
	}
	else
	{
		ft_setup_delete(setup);
		ft_putendl("program exited normally");
		exit (0);
		//return (1);
	}
}
