/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:13:20 by psebasti          #+#    #+#             */
/*   Updated: 2017/04/19 16:02:37 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t	ft_mandelbrot_init(t_setup *setup)
{
	if (!(MAN = (t_fract *)ft_memalloc(sizeof(t_fract))))
		return (0);
	MAN->it_max = 50;
	MAN->zoom = 300;
	MAN->x1 = -2.05;
	MAN->y1 = -1.3;
	MAN->lerp_in = ft_colornew(0, 0, 0);
	MAN->lerp_out = ft_colornew(255, 255, 255);
	if (MAN->lerp_in && MAN->lerp_out)
		return (1);
	return (0);
}
