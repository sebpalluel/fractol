/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:09:10 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/16 18:50:22 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t		ft_fract_calc(t_setup *setup)
{
	printf("fract_calc\n");
	if (setup->f_mode == 0 || setup->f_mode == 3)
		if (ft_fractol_pthread(setup, 0, ft_mandelbrot) != 0)
			return (0);
	if (setup->f_mode == 1 || setup->f_mode == 3)
		if (ft_fractol_pthread(setup, 1, ft_julia) != 0)
			return (0);
	return (1);
}

int			main(int ac, char **av)
{
	t_setup	*setup = NULL;

	if (ac == 2)
	{
		if (!(setup = (t_setup *)malloc(sizeof(t_setup) * NUM_THREAD + 1)))
			return (-1);
		if (ft_setup_mode(av, setup, 1))
			ft_mlx_process(setup);
		return (ft_setup_mode(av, setup, 0));
	}
	return (ft_error_usage());
}
