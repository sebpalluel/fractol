/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cantor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 18:18:36 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/05 20:42:48 by psebasti         ###   ########.fr       */
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

	coef = 50.;
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

static void		ft_draw_line(t_setup *setup, t_vec3 start, t_vec3 end)
{
	//printf("start.x %f start.y %f\n", start.x, start.y);
	//printf("end.x %f end.y %f\n", end.x, end.y);
	while (start.x < end.x)
	{
		ft_put_pxl_to_img(setup, start, ft_cantor_give_color(setup));
		start.x++;
	}
}

static void		ft_cantor_calc(t_setup *setup, double x, double y, double len)
{
	t_vec3		tmp1;
	t_vec3		tmp2;

	if (len >= 1)
	{
		//CAN->vec.x = x + len;
		//CAN->vec.y = y;
		//ft_draw_line(setup, CAN->pos, CAN->vec);
		//CAN->pos.y += 20;
		//ft_cantor_calc(setup, CAN->pos.x, CAN->pos.y, len / 3);
		//ft_cantor_calc(setup, CAN->pos.x + len * 2 / 3, CAN->pos.y, len / 3);

		tmp1.x = x;
		tmp1.y = y;
		tmp2.x = x + len;
		tmp2.y = y;
		ft_draw_line(setup, tmp1, tmp2);
		y += 20;
		ft_cantor_calc(setup, x, y, len / 3);
		ft_cantor_calc(setup, x + len * 2 / 3, y, len / 3);
	}
}

void			*ft_cantor(void *tab)
{
	t_setup	*setup;
//	double	tmp;

	setup = (t_setup *)tab;
	CAN->pos.x = 0;
//	tmp = CAN->pos.y;
	//while (CAN->pos.x < setup->width)
	//{
//		CAN->pos.y = tmp;
		while (CAN->pos.y < setup->height)
		{
			ft_cantor_calc(setup, CAN->pos.x, CAN->pos.y, setup->width);
			CAN->pos.y += 100;
			CAN->it++;
		}
	//	CAN->pos.x++;
	//}
	return (tab);
}
