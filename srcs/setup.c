/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:58:45 by psebasti          #+#    #+#             */
/*   Updated: 2017/06/23 16:42:51 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//static size_t	ft_setup_fract_init(t_setup *setup)
//{
//	size_t i;
//	size_t j;
//
//	i = 0;
//	j = 0;
//	if (!(setup->fract = (t_fract **)ft_memalloc(sizeof(t_fract *) * 4)))
//		return (0);
//	while (i < 3)
//	{
//		if(!(setup->fract[i] = (t_fract *)ft_memalloc(sizeof(t_fract)))\
//				|| !(setup->fract[i]->clr = (t_color **)\
//					ft_memalloc(sizeof(t_color *) * 4)))
//			return (0);
//		while (j < 3)
//		{
//			if (!(setup->fract[i]->clr[j] = ft_colornew(0, 0, 0)))
//				return (0);
//			j++;
//			setup->fract[i]->clr[j] = NULL;
//		}
//		i++;
//	}
//	setup->fract[i] = NULL;
//	return (1);
//}

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
		while (++frac_n < 3)
		{
			col_n = -1;
			while (++col_n < 3)
				free (setup[i].fract[frac_n]->clr[col_n]);
			free (setup[i].fract[frac_n]);
		}
		free (setup[i].fract);
	}
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
		av[0] = "223";
		SETUP.f_mode = 666;
			return (ft_error_usage());
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
		exit (0);
	}
}
