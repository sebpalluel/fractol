/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cantor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:18:36 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/05 19:12:40 by psebasti         ###   ########.fr       */
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

void		ft_draw_line(t_setup *setup, t_vec3 start, t_vec3 end)
{
	t_vec3	tmp;

	if ((end.x - start.x) * (end.x - start.x) < 2 && (end.y - start.y) \
			* (end.y - start.y) < 2)
		return ;
	tmp.x = (start.x + end.x) * 0.5;
	tmp.y = (start.y + end.y) * 0.5;
	ft_put_pxl_to_img(setup, CAN, ft_cantor_give_color(setup));
	ft_draw_line(setup, start, tmp);
	ft_draw_line(setup, tmp, end);
}

static void		ft_cantor_calc(t_setup *setup)
{
	if (len >= 1)
	{
		p1 = (t_cord*)malloc(sizeof(t_cord));
		p2 = (t_cord*)malloc(sizeof(t_cord));
		p1->x = x;
		p1->y = y;
		p2->x = x + len;
		p2->y = y;
		ft_draw_line(p1, p2, e);
		y += 20;
		cantor_line(x, y, len / 3, e);
		cantor_line(x + len * 2 / 3, y, len / 3, e);
	}
	ft_put_pxl_to_img(setup, CAN, ft_cantor_give_color(setup));
}

void			*ft_cantor(void *tab)
{
	t_setup	*setup;
	double	tmp;

	setup = (t_setup *)tab;
	CAN->x = 0;
	tmp = CAN->y;
		while (CAN->x < setup->width)
	{
		CAN->y = tmp;
		while (CAN->y < setup->height)
		{
			ft_cantor_calc(setup);
			CAN->y++;
			CAN->it++;
		}
		CAN->x++;
	}
	return (tab);
}
