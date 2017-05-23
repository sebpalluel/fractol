/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:55:22 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/19 14:39:03 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_zoom(int x, int y, t_fract *fract)
{
	fract->x2 = x;
	fract->y2 = y;
	fract->x1 = (x / fract->zoom + fract->x1) - ((fract->zoom * 1.3) / 2);
	fract->x1 += ((fract->zoom * 1.3) / 2) - (x / (fract->zoom * 1.3));
	fract->y1 = (y / fract->zoom + fract->y1) - ((fract->zoom * 1.3) / 2);
	fract->y1 += ((fract->zoom * 1.3) / 2) - (y / (fract->zoom * 1.3));
	fract->zoom *= 1.3;
	fract->it_max++;
}

static void	ft_dezoom(t_fract *fract)
{
	fract->x1 = (fract->x2 / fract->zoom + fract->x1) - ((fract->zoom / 1.3) / 2);
	fract->x1 += ((fract->zoom / 1.3) / 2) - (fract->x2 / (fract->zoom / 1.3));
	fract->y1 = (fract->y2 / fract->zoom + fract->y1) - ((fract->zoom / 1.3) / 2);
	fract->y1 += ((fract->zoom / 1.3) / 2) - (fract->y2 / (fract->zoom / 1.3));
	fract->zoom /= 1.3;
	fract->it_max--;
}

int			ft_mouse_hook(int mousecode, int x, int y, t_setup *setup)
{
	int		frac;

	frac = -1;
	if (setup->f_mode < 3)
	{
		if (mousecode == 4 || mousecode == 1)
			ft_zoom(x, y, setup->fract[setup->f_mode]);
		else if (mousecode == 5 || mousecode == 2)
			ft_dezoom(setup->fract[setup->f_mode]);
	}
	else
	{
		if (mousecode == 4 || mousecode == 1)
			while (++frac < 3)
				ft_zoom(x, y, setup->fract[frac]);
		else if (mousecode == 5 || mousecode == 2)
			while (++frac < 3)
				ft_dezoom(setup->fract[frac]);
	}
	return (1);
}
