/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:13:36 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/12 21:03:08 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			ft_julia_init(t_setup *setup)
{
	JUL->it_max = 50;
	JUL->zoom = 200;
	JUL->vec.x = -2.0;
	JUL->vec.y = -1.9;
	JUL->c_r = 0.285;
	JUL->c_i = 0.01;
	ft_color(JUL->clr[0], 0, 0, 0);
	ft_color(JUL->clr[1], 255, 255, 255);
	ft_color(JUL->clr[2], 255, 255, 255);
}

static t_color	*ft_julia_give_color(t_setup *setup)
{
	double coef;

	coef = JUL->it / 25.;
	if (JUL->clr[1]->r - JUL->clr[0]->r)
		JUL->clr[2]->r = (double)(JUL->clr[1]->r - JUL->clr[0]->r) * coef;
	else
		JUL->clr[2]->r = JUL->clr[1]->r;
	if (JUL->clr[1]->g - JUL->clr[0]->g)
		JUL->clr[2]->g = (double)(JUL->clr[1]->g - JUL->clr[0]->g) * coef;
	else
		JUL->clr[2]->g = JUL->clr[1]->g;
	if (JUL->clr[1]->b - JUL->clr[0]->b)
		JUL->clr[2]->b = (double)(JUL->clr[1]->b - JUL->clr[0]->b) * coef;
	else
		JUL->clr[2]->b = JUL->clr[1]->b;
	return (JUL->clr[2]);
}

static void		ft_julia_calc(t_setup *setup)
{
	JUL->z_r = JUL->pos.x / JUL->zoom + JUL->vec.x;
	JUL->z_i = JUL->pos.y / JUL->zoom + JUL->vec.y;
	JUL->it = 0;
	while (JUL->z_r * JUL->z_r + JUL->z_i *
			JUL->z_i < 4 && JUL->it < JUL->it_max)
	{
		JUL->tmp = JUL->z_r;
		JUL->z_r = JUL->z_r * JUL->z_r -
			JUL->z_i * JUL->z_i - 0.8 + (JUL->c_r / setup->width);
		JUL->z_i = 2 * JUL->z_i * JUL->tmp + JUL->c_i / setup->width;
		JUL->it++;
	}
	ft_put_pxl_to_img(setup, JUL->pos, ft_julia_give_color(setup));
}

void			*ft_julia(void *tab)
{
	t_setup	*setup;
	double	tmp;

	setup = (t_setup *)tab;
	JUL->pos.x = 0;
	tmp = JUL->pos.y;
	while (JUL->pos.x < setup->width)
	{
		JUL->pos.y = tmp;
		while (JUL->pos.y < JUL->height_max)
		{
			ft_julia_calc(setup);
			JUL->pos.y++;
		}
		JUL->pos.x++;
	}
	return (tab);
}
