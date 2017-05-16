/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:58:45 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/16 16:34:40 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_fract	**ft_setup_fract_init()
{
	size_t		i;
	t_fract		**fract = NULL;

	i = 0;
	if (!(fract = (t_fract **)ft_memalloc(sizeof(t_fract *) * 4)))
		return (NULL);
	while (i < 3)
	{
		if(!(fract[i] = (t_fract *)ft_memalloc(sizeof(t_fract))))
			return (NULL);
		if (!(fract[i]->clr_tmp = ft_colornew(0, 0, 0))\
				|| !(fract[i]->lerp_in = ft_colornew(0, 0, 0))\
				|| !(fract[i]->lerp_out = ft_colornew(0, 0, 0)))
			return (NULL);
		i++;
	}
	fract[i] = NULL;
	return (fract);
}

static size_t	ft_setup_f_mode(t_setup *setup)
{
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
	size_t		i;

	SETUP.width = WIDTH;
	SETUP.height = HEIGHT;
	MLX = ft_initwindow("fractol", SETUP.width, SETUP.height);
	IMG = ft_imgnew(MLX->mlx_ptr, SETUP.width, SETUP.height);
	i = 1;
	while (i < NUM_THREAD + 1)
	{
		ft_memcpy((void *)&setup[i], (void *)&SETUP, sizeof(t_setup));
		setup[i].mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
		setup[i].img = (t_img *)ft_memalloc(sizeof(t_img));
		if (!setup[i].mlx || !setup[i].img || \
				!(setup[i].fract = ft_setup_fract_init()))
			return (0);
		ft_memcpy((void *)setup[i].mlx, (void *)SETUP.mlx, sizeof(t_mlx));
		ft_memcpy((void *)setup[i].img, (void *)SETUP.img, sizeof(t_img));
		i++;
	}
	if (MLX && IMG && (SETUP.fract = ft_setup_fract_init()) && \
			ft_setup_f_mode(&SETUP))
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

int				ft_error_usage()
{
	ft_putendl("Usage:\n\
			./fractol \"mandelbrot\"\n\
			./fractol \"julia\"\n\
			./fractol \"burningship\"\n\
			./fractol \"all\"");
	return (0);
}

size_t			ft_setup_mode(char **av, t_setup *setup, size_t mode)
{
	size_t		i;

	i = 0;
	if (mode)
	{
		SETUP.f_mode = 666;
		ft_setup_fract_select(av, &SETUP);
		if (ft_setup_init(setup) != 1 || SETUP.f_mode == 666)
			return (ft_error_usage());
		return (1);
	}
	else
	{
		while (i < NUM_THREAD + 1)
		{
			ft_setup_delete(&setup[i]);
			i++;
		}
		if (SETUP.f_mode != 666)
			ft_putendl("program exited normally");
		exit (0);
	}
}
