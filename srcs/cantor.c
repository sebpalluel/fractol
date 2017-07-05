/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cantor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:18:36 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/05 19:58:09 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_cantor_init(t_setup *setup)
{
	CAN->it_max = 50;
	ft_color(CAN->clr[0], 0, 0, 0);
	ft_color(CAN->clr[1], 255, 255, 255);
	ft_color(CAN->clr[2], 255, 255, 255);
}

static t_color 	*ft_cantor_give_color(t_setup *setup)
{
	double coef;

	coef = CAN->it/50.;
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

void		ft_draw_line(t_setup *setup, t_vec3 *start, t_vec3 *end)
{
	t_vec3	tmp;

	if ((end->x - start->x) * (end->x - start->x) < 2 && (end->y - start->y) \
			* (end->y - start->y) < 2)
		return ;
	tmp.x = (start->x + end->x) * 0.5;
	tmp.y = (start->y + end->y) * 0.5;
	ft_put_pxl_to_img(setup, CAN, ft_cantor_give_color(setup));
	ft_draw_line(setup, start, &tmp);
	ft_draw_line(setup, &tmp, end);
}

static void		ft_cantor_calc(t_setup *setup, double x, double y, double len)
{
	if (len >= 1)
	{
		CAN->vec.x = CAN->pos.x + len;
		CAN->vec.y = CAN->pos.y;
		ft_draw_line(setup, &CAN->pos, &CAN->vec);
		CAN->pos.y += 20;
		ft_cantor_calc(setup, x, y, len / 3);
		ft_cantor_calc(setup, x + len * 2 / 3, y, len / 3);
	}
}

void			*ft_cantor(void *tab)
{
	t_setup	*setup;
	double	tmp;

	setup = (t_setup *)tab;
	CAN->pos.x = 0;
	tmp = CAN->pos.y;
		while (CAN->pos.x < setup->width)
	{
		CAN->pos.y = tmp;
		while (CAN->pos.y < setup->height)
		{
			ft_cantor_calc(setup, CAN->pos.x, CAN->pos.y, setup->width);
			CAN->pos.y += 100;
			CAN->it++;
		}
		CAN->pos.x++;
	}
	return (tab);
}
