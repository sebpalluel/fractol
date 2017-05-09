/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:58:45 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/09 17:27:38 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static size_t	ft_setup_fract_init(t_setup *setup)
{
	if (!(setup->fract = (t_fract **)ft_memalloc(sizeof(t_fract *) * 3)))
		return (0);
	if (setup->f_mode == 0 || setup->f_mode == 3)
		ft_mandelbrot_init(setup);
	if (setup->f_mode == 1 || setup->f_mode == 3)
		ft_julia_init(setup);
	//if (setup->f_mode == 2 || setup->f_mode == 3)
	//ft_burningship_init(setup);
	return (1);
}

size_t			ft_setup_init(t_setup *setup)
{
	setup->width = WIDTH;
	setup->height = HEIGHT;
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
	int			frac_n;

	frac_n = -1;
	if (IMG)
		ft_imgdel(IMG, MLX->mlx_ptr);
	if (MLX)
		ft_mlxdelete(MLX);
	if (setup->fract)
	{
		while (++frac_n < 3)
			free (setup->fract[frac_n]);
		free (setup->fract);
	}
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
}

static size_t	ft_error_usage()
{
	ft_putendl("Usage:\n\
	./fractol \"mandelbrot\"\n\
	./fractol \"julia\"\n\
	./fractol \"burningship\"\n\
	./fractol \"all\"");
	return (0);
}

size_t			ft_setup_mode(int ac, char **av, t_setup *setup, size_t mode)
{
	if (mode)
	{
		setup->f_mode = 666;
		if (ac == 2)
			ft_setup_fract_select(av, setup);
		if (ft_setup_init(setup) != 1 || setup->f_mode == 666)
			return (ft_error_usage());
		return (1);
	}
	else
	{
		ft_setup_delete(setup);
		if (setup->f_mode != 666)
			ft_putendl("program exited normally");
		exit (0);
	}
}
