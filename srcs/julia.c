/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:13:36 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/05 16:47:25 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t		ft_julia_init(t_setup *setup)
{
	if (!(JUL = (t_fract *)ft_memalloc(sizeof(t_fract))))
		return (0);
	JUL->it_max = 50;
	JUL->zoom = 200;
	JUL->x1 = -2.0;
	JUL->y1 = -1.9;
	JUL->c_r = 0.285;
	JUL->c_i = 0.01;
	JUL->clr_tmp = ft_colornew(0, 0, 0);
	JUL->lerp_in = ft_colornew(0, 0, 0);
	JUL->lerp_out = ft_colornew(255, 255, 255);
	if (JUL->lerp_in && JUL->lerp_out)
		return (1);
	return (0);
}

t_color 	*ft_julia_give_color(t_setup *setup)
{

	return (JUL->clr_tmp);
}

static void	ft_julia_calc(t_setup *setup)
{
	JUL->c_r = JUL->x / JUL->zoom + JUL->x1;
	JUL->c_i = JUL->y / JUL->zoom + JUL->y1;
	JUL->it = 0;
	while (JUL->z_r * JUL->z_r + JUL->z_i *
			JUL->z_i < 4 && JUL->it < JUL->it_max)
	{
		JUL->tmp = JUL->z_r;
		JUL->z_r = JUL->z_r * JUL->z_r -
			JUL->z_i * JUL->z_i - 0.8 + (JUL->c_r / WIDTH);
		JUL->z_i = 2 * JUL->z_i * JUL->tmp + JUL->c_i / WIDTH;
		JUL->it++;
	}
	if (JUL->it == JUL->it_max)
		ft_put_pxl_to_img(setup, JUL, JUL->lerp_out);
	else
		ft_put_pxl_to_img(setup, JUL, ft_julia_give_color(setup));
}

void		*ft_julia(void *tab)
{
	t_setup	*setup;
	double	tmp;

	setup = (t_setup *)tab;
	JUL->x = 0;
	tmp = JUL->y;
	while (JUL->x < WIDTH)
	{
		JUL->y = tmp;
		while (JUL->y < JUL->y_max)
		{
			ft_julia_calc(setup);
			JUL->y++;
		}
		JUL->x++;
	}
	return (tab);
}
