/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:13:20 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/17 19:32:41 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_mandelbrot_init(t_setup *setup)
{
	MAN->it_max = 50;
	MAN->zoom = 200;
	MAN->x1 = -2.0;
	MAN->y1 = -1.9;
	MAN->c_r = 0.285;
	MAN->c_i = 0.01;
	ft_color(MAN->clr[0], 0, 0, 0);
	ft_color(MAN->clr[1], 0, 0, 0);
	ft_color(MAN->clr[2], 255, 255, 255);
}

t_color 	*ft_mandelbrot_give_color(t_setup *setup)
{

	return (MAN->clr[0]);
}

static void	ft_mandelbrot_calc(t_setup *setup)
{
	MAN->c_r = MAN->x / MAN->zoom + MAN->x1;
	MAN->c_i = MAN->y / MAN->zoom + MAN->y1;
	MAN->z_r = 0;
	MAN->z_i = 0;
	MAN->it = 0;
	while (MAN->z_r * MAN->z_r + MAN->z_i *
			MAN->z_i < 4 && MAN->it < MAN->it_max)
	{
		MAN->tmp = MAN->z_r;
		MAN->z_r = MAN->z_r * MAN->z_r -
			MAN->z_i * MAN->z_i + MAN->c_r;
		MAN->z_i = 2 * MAN->z_i * MAN->tmp + MAN->c_i;
		MAN->it++;
	}
	if (MAN->it == MAN->it_max)
		ft_put_pxl_to_img(setup, MAN, MAN->clr[2]);
	else
		ft_put_pxl_to_img(setup, MAN, ft_mandelbrot_give_color(setup));
}

void		*ft_mandelbrot(void *tab)
{
	t_setup	*setup;
	double	tmp;

	setup = (t_setup *)tab;
	MAN->x = 0;
	tmp = MAN->y;
	printf("tmp %f\n", MAN->y);
	printf("width %lu\n", setup->width);
	while (MAN->x < setup->width)
	{
		MAN->y = tmp;
		while (MAN->y < MAN->y_max)
		{
			ft_mandelbrot_calc(setup);
			MAN->y++;
		}
		MAN->x++;
	}
	return (tab);
}
