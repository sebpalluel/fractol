/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:13:20 by psebasti          #+#    #+#             */
/*   Updated: 2017/06/28 18:31:20 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_mandelbrot_init(t_setup *setup)
{
	MAN->it_max = 50;
	MAN->zoom = 200;
	MAN->x1 = -2.0;
	MAN->y1 = -1.9;
	MAN->c_r = 0.285;
	MAN->c_i = 0.01;
	ft_color(MAN->clr[0], 0, 0, 0);
	ft_color(MAN->clr[1], 255, 255, 255);
	ft_color(MAN->clr[2], 255, 255, 255);
}

static t_color 	*ft_mandelbrot_give_color(t_setup *setup)
{
	double coef;

	coef = MAN->it/50.;
	if (MAN->clr[1]->r - MAN->clr[0]->r)
		MAN->clr[2]->r = (double)(MAN->clr[1]->r - MAN->clr[0]->r) * coef;
	else
		MAN->clr[2]->r = MAN->clr[1]->r;
	if (MAN->clr[1]->g - MAN->clr[0]->g)
		MAN->clr[2]->g = (double)(MAN->clr[1]->g - MAN->clr[0]->g) * coef;
	else
		MAN->clr[2]->g = MAN->clr[1]->g;
	if (MAN->clr[1]->b - MAN->clr[0]->b)
		MAN->clr[2]->b = (double)(MAN->clr[1]->b - MAN->clr[0]->b) * coef;
	else
		MAN->clr[2]->b = MAN->clr[1]->b;
	return (MAN->clr[2]);
}

static void		ft_mandelbrot_calc(t_setup *setup)
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
	ft_put_pxl_to_img(setup, MAN, ft_mandelbrot_give_color(setup));
}

void			*ft_mandelbrot(void *tab)
{
	t_setup	*setup;
	double	tmp;

	setup = (t_setup *)tab;
	MAN->x = 0;
	tmp = MAN->y;
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
