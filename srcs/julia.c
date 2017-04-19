/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:13:36 by psebasti          #+#    #+#             */
/*   Updated: 2017/04/18 20:25:54 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t	ft_mandelbrot_init(t_setup *setup)
{
	if (!(JUL = (t_fract *)ft_memalloc(sizeof(t_fract))))
		return (0);
	JUL->it_max = 50;
	JUL->zoom = 200;
	JUL->x1 = -2.0;
	JUL->y1 = -1.9;
	JUL->c_r = 0.285;
	JUL->c_i = 0.01;
	JUL->lerp_in = (t_color *)ft_memalloc(sizeof(t_color));
	JUL->lerp_out = (t_color *)ft_memalloc(sizeof(t_color));
	if (JUL->lerp_in && JUL->lerp_out)
		return (1);
	return (0);
}
