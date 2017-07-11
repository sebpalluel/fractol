/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:58:45 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/11 14:37:57 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static size_t	ft_setup_fract_init(t_setup *setup)
{
	size_t i;
	size_t j;

	i = 0;
	if (!(setup->fract = (t_fract **)ft_memalloc(sizeof(t_fract *) * FNUM)))
		return (0);
	while (i < FNUM)
	{
		if(!(setup->fract[i] = (t_fract *)ft_memalloc(sizeof(t_fract)))\
				|| !(setup->fract[i]->clr = (t_color **)\
					ft_memalloc(sizeof(t_color *) * FNUM)))
			return (0);
		j = 0;
		while (j < FNUM)
		{
			if (!(setup->fract[i]->clr[j] = ft_colornew(0, 0, 0)))
				return (0);
			j++;
			setup->fract[i]->clr[j] = NULL;
		}
		i++;
	}
	setup->fract[i] = NULL;
	return (1);
}

static void		ft_setup_delete(size_t i, t_setup *setup)
{
	int			frac_n;
	int			col_n;

	frac_n = -1;
	if (IMG)
		ft_imgdel(IMG, MLX->mlx_ptr);
	if (MLX)
		ft_mlxdelete(MLX);
	if (setup[i].fract)
	{
		while (++frac_n < FNUM)
		{
			col_n = -1;
			while (++col_n < FNUM)
				free (setup[i].fract[frac_n]->clr[col_n]);
			free (setup[i].fract[frac_n]);
		}
		free (setup[i].fract);
	}
}

size_t			ft_setup_mode(t_setup *setup, size_t mode)
{
	size_t		i;

	i = 0;
	if (mode)
	{
		SETUP.f_mode = 666;
		setup->width = WIDTH;
		setup->height = HEIGHT;
		MLX = ft_initwindow("fractol", SETUP.width, SETUP.height);
		IMG = ft_imgnew(MLX->mlx_ptr, SETUP.width, SETUP.height);
		ft_setup_fract_init(&SETUP);
		return (1);
	}
	else
	{
		while (i < NUM_THREAD + 1)
		{
			ft_setup_delete(i, setup);
			i++;
		}
		if (SETUP.f_mode != 666)
			ft_putendl("program exited normally");
		else
			ft_error_usage();
		exit (0);
	}
}
