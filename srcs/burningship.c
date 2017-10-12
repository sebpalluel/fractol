/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 14:12:05 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/12 12:58:11 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_burningship_init(t_setup *setup)
{
	BUR->it_max = 50;
	BUR->zoom = 200;
	BUR->vec.x = -3.;
	BUR->vec.y = -3.;
	ft_color(BUR->clr[0], 0, 0, 0);
	ft_color(BUR->clr[1], 255, 255, 255);
	ft_color(BUR->clr[2], 255, 255, 255);
}

static int		ft_burningship_give_color(t_setup *setup)
{
	double coef;

	coef = BUR->it / 50.;
	if (BUR->clr[1]->r - BUR->clr[0]->r)
		BUR->clr[2]->r = (BUR->clr[1]->r - BUR->clr[0]->r) * coef;
	else
		BUR->clr[2]->r = BUR->clr[1]->r;
	if (BUR->clr[1]->g - BUR->clr[0]->g)
		BUR->clr[2]->g = (BUR->clr[1]->g - BUR->clr[0]->g) * coef;
	else
		BUR->clr[2]->g = BUR->clr[1]->g;
	if (BUR->clr[1]->b - BUR->clr[0]->b)
		BUR->clr[2]->b = (BUR->clr[1]->b - BUR->clr[0]->b) * coef;
	else
		BUR->clr[2]->b = BUR->clr[1]->b;
	if (setup->drunk_mode)
		return ((int)ft_stoul("c0000000", 16) + ft_colortohex(BUR->clr[2]));
	else
		return (ft_colortohex(BUR->clr[2]));
}

static void		ft_burningship_calc(t_setup *setup)
{
	BUR->c_r = BUR->pos.x / BUR->zoom + BUR->vec.x;
	BUR->c_i = BUR->pos.y / BUR->zoom + BUR->vec.y;
	BUR->z_r = 0.18;
	BUR->z_i = 0.4;
	BUR->it = 0;
	BUR->ratio_i = (setup->i_ratio ? BUR->ratio_i : 2.);
	while (BUR->z_r * BUR->z_r + BUR->z_i *
			BUR->z_i < 4 && BUR->it < BUR->it_max)
	{
		BUR->tmp = BUR->z_r * BUR->z_r - BUR->z_i * BUR->z_i + BUR->c_r;
		BUR->z_i = BUR->c_i + fabs(BUR->ratio_i * BUR->z_i * BUR->z_r);
		BUR->z_r = BUR->tmp;
		BUR->it++;
	}
	if (setup->f_mode != 4 && BUR->it > 4.)
	ft_put_pixel(setup, BUR->pos.x, BUR->pos.y, \
			ft_burningship_give_color(setup));
}

void			*ft_burningship(void *tab)
{
	t_setup	*setup;
	double	tmp;

	setup = (t_setup *)tab;
	BUR->pos.x = 0;
	tmp = BUR->pos.y;
	while (BUR->pos.x < setup->width)
	{
		BUR->pos.y = tmp;
		while (BUR->pos.y < BUR->height_max)
		{
			ft_burningship_calc(setup);
			BUR->pos.y++;
		}
		BUR->pos.x++;
	}
	return (tab);
}
