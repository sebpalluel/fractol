/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cantor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:18:36 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/11 18:30:55 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_cantor_init(t_setup *setup)
{
	ft_color(CAN->clr[0], 0, 0, 0);
	ft_color(CAN->clr[1], 255, 255, 255);
	ft_color(CAN->clr[2], 255, 255, 255);
}

static int		ft_cantor_give_color(t_setup *setup)
{
	double coef;

	coef = CAN->vec.x / CAN->vec.y;
	if (CAN->clr[1]->r - CAN->clr[0]->r)
		CAN->clr[2]->r = (CAN->clr[1]->r - CAN->clr[0]->r) * coef;
	else
		CAN->clr[2]->r = CAN->clr[1]->r;
	if (CAN->clr[1]->g - CAN->clr[0]->g)
		CAN->clr[2]->g = (CAN->clr[1]->g - CAN->clr[0]->g) * coef;
	else
		CAN->clr[2]->g = CAN->clr[1]->g;
	if (CAN->clr[1]->b - CAN->clr[0]->b)
		CAN->clr[2]->b = (CAN->clr[1]->b - CAN->clr[0]->b) * coef;
	else
		CAN->clr[2]->b = CAN->clr[1]->b;
	if (setup->drunk_mode || setup->f_mode == 4)
		return ((int)ft_stoul("c0000000", 16) + ft_colortohex(CAN->clr[2]));
	else
		return (ft_colortohex(CAN->clr[2]));
}

static void		ft_cantor_line(t_setup *setup, t_vec3 start, t_vec3 end)
{
	size_t		width;

	width = 0;
	while (width < 5)
	{
		CAN->tmp = start.x;
		while (start.x <= end.x)
		{
			ft_put_pixel(setup, CAN->pos.x, CAN->pos.y, \
					ft_cantor_give_color(setup));
			start.x++;
		}
		start.x = CAN->tmp;
		start.y++;
		width++;
	}
}

static void		ft_cantor_calc(t_setup *setup, double x, double y, double len)
{
	t_vec3		tmp;

	if (len > 1. && y <= CAN->height_max)
	{
		tmp.x = x;
		tmp.y = y;
		CAN->vec.x = x + len;
		CAN->vec.y = y;
		ft_cantor_line(setup, tmp, CAN->vec);
		y += 40.;
		ft_cantor_calc(setup, x, y, len / 3);
		ft_cantor_calc(setup, x + len * 2 / 3, y, len / 3);
	}
}

void			*ft_cantor(void *tab)
{
	t_setup		*setup;

	setup = tab;
	setup = (t_setup *)tab;
	CAN->pos.x = 0;
	ft_cantor_calc(setup, CAN->pos.x, CAN->pos.y, setup->width);
	CAN->pos.y = CAN->height_max;
	return (tab);
}
