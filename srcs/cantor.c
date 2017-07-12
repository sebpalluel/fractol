/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cantor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:18:36 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/12 20:59:17 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_cantor_init(t_setup *setup)
{
	ft_color(CAN->clr[0], 0, 0, 0);
	ft_color(CAN->clr[1], 255, 255, 255);
	ft_color(CAN->clr[2], 255, 255, 255);
}

static t_color 	*ft_cantor_give_color(t_setup *setup)
{
	double coef;

	coef = CAN->vec.x / CAN->vec.y;
	if (CAN->clr[1]->r - CAN->clr[0]->r)
		CAN->clr[2]->r = (double)(CAN->clr[1]->r - CAN->clr[0]->r) * coef;
	else
		CAN->clr[2]->r = CAN->clr[1]->r;
	if (CAN->clr[1]->g - CAN->clr[0]->g)
		CAN->clr[2]->g = (double)(CAN->clr[1]->g - CAN->clr[0]->g) * coef;
	else
		CAN->clr[2]->g = CAN->clr[1]->g;
	if (CAN->clr[1]->b - CAN->clr[0]->b)
		CAN->clr[2]->b = (double)(CAN->clr[1]->b - CAN->clr[0]->b) * coef;
	else
		CAN->clr[2]->b = CAN->clr[1]->b;
	return (CAN->clr[2]);
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
			ft_put_pxl_to_img(setup, start, ft_cantor_give_color(setup));
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

	if (len >= 1)
	{
		tmp.x = x;
		tmp.y = y;
		CAN->vec.x = x + len;
		CAN->vec.y = y;
		ft_cantor_line(setup, tmp, CAN->vec);
		y += 25;
		ft_cantor_calc(setup, x, y, len / 3);
		ft_cantor_calc(setup, x + len * 2 / 3, y, len / 3);
	}
}

void			*ft_cantor(void *tab)
{
	t_setup	*setup;

	setup = tab;
	CAN->it = 0;
	setup = (t_setup *)tab;
	CAN->pos.x = 0;
	while (CAN->pos.y < CAN->height_max)
	{
		ft_cantor_calc(setup, CAN->pos.x, CAN->pos.y, setup->width);
		CAN->pos.y += 100;
		CAN->it++;
	}
	return (tab);
}
