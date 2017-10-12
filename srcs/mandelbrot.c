/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:13:20 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/12 15:13:31 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_mandelbrot_init(t_setup *setup)
{
	MAN->it_max = 50;
	MAN->zoom = 200;
	MAN->vec.x = -3.;
	MAN->vec.y = -2.6;
	MAN->c_r = 0.298;
	MAN->c_i = -0.01;
	ft_color(MAN->clr[0], 0, 0, 0);
	ft_color(MAN->clr[1], 255, 255, 255);
	ft_color(MAN->clr[2], 255, 255, 255);
}

static int		ft_mandelbrot_give_color(t_setup *setup)
{
	double coef;

	coef = MAN->it / 50.;
	if (MAN->clr[1]->r - MAN->clr[0]->r)
		MAN->clr[2]->r = (MAN->clr[1]->r - MAN->clr[0]->r) * coef;
	else
		MAN->clr[2]->r = MAN->clr[1]->r;
	if (MAN->clr[1]->g - MAN->clr[0]->g)
		MAN->clr[2]->g = (MAN->clr[1]->g - MAN->clr[0]->g) * coef;
	else
		MAN->clr[2]->g = MAN->clr[1]->g;
	if (MAN->clr[1]->b - MAN->clr[0]->b)
		MAN->clr[2]->b = (MAN->clr[1]->b - MAN->clr[0]->b) * coef;
	else
		MAN->clr[2]->b = MAN->clr[1]->b;
	if (setup->drunk_mode || setup->f_mode == 4)
		return ((int)ft_stoul("c0000000", 16) + ft_colortohex(MAN->clr[2]));
	else
		return (ft_colortohex(MAN->clr[2]));
}

static void		ft_mandelbrot_calc(t_setup *setup)
{
	MAN->c_r = MAN->pos.x / MAN->zoom + MAN->vec.x;
	MAN->c_i = MAN->pos.y / MAN->zoom + MAN->vec.y;
	MAN->z_r = 0;
	MAN->z_i = 0;
	MAN->it = 0;
	MAN->ratio_i = (setup->i_ratio ? MAN->ratio_i : 2.);
	while (MAN->z_r * MAN->z_r + MAN->z_i *
			MAN->z_i < 4 && MAN->it < MAN->it_max)
	{
		MAN->tmp = MAN->z_r;
		MAN->z_r = MAN->z_r * MAN->z_r -
			MAN->z_i * MAN->z_i + MAN->c_r;
		MAN->z_i = MAN->ratio_i * MAN->z_i * MAN->tmp + MAN->c_i;
		MAN->it++;
	}
	if (setup->f_mode != 4 && MAN->it > 4.)
		ft_put_pixel(setup, MAN->pos.x, MAN->pos.y, \
				ft_mandelbrot_give_color(setup));
}

void			*ft_mandelbrot(void *tab)
{
	t_setup	*setup;
	double	tmp;

	setup = (t_setup *)tab;
	MAN->pos.x = 0;
	tmp = MAN->pos.y;
	while (MAN->pos.x < setup->width)
	{
		MAN->pos.y = tmp;
		while (MAN->pos.y < MAN->height_max)
		{
			ft_mandelbrot_calc(setup);
			MAN->pos.y++;
		}
		MAN->pos.x++;
	}
	return (tab);
}
