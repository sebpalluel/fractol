/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:55:22 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/05 19:25:11 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_zoom(int x, int y, t_fract *fract)
{
	fract->focus.x = x;
	fract->focus.y = y;
	fract->vec.x = (x / fract->zoom + fract->vec.x) - ((fract->zoom * 1.3) / 2);
	fract->vec.x += ((fract->zoom * 1.3) / 2) - (x / (fract->zoom * 1.3));
	fract->vec.y = (y / fract->zoom + fract->vec.y) - ((fract->zoom * 1.3) / 2);
	fract->vec.y += ((fract->zoom * 1.3) / 2) - (y / (fract->zoom * 1.3));
	fract->zoom *= 1.3;
	fract->it_max++;
}

static void	ft_dezoom(t_fract *fract)
{
	fract->vec.x = (fract->focus.x / fract->zoom + fract->vec.x) - ((fract->zoom / 1.3) / 2);
	fract->vec.x += ((fract->zoom / 1.3) / 2) - (fract->focus.x / (fract->zoom / 1.3));
	fract->vec.y = (fract->focus.y / fract->zoom + fract->vec.y) - ((fract->zoom / 1.3) / 2);
	fract->vec.y += ((fract->zoom / 1.3) / 2) - (fract->focus.y / (fract->zoom / 1.3));
	fract->zoom /= 1.3;
	fract->it_max--;
}

int			ft_mouse_hook(int mousecode, int x, int y, t_setup *param)
{
	t_setup	*setup;
	int		frac;

	setup = param;
	frac = -1;
	if (SETUP.f_mode < 3)
	{
		if (mousecode == 4 || mousecode == 1)
			ft_zoom(x, y, SETUP.fract[SETUP.f_mode]);
		else if (mousecode == 5 || mousecode == 2)
			ft_dezoom(SETUP.fract[SETUP.f_mode]);
	}
	else
	{
		if (mousecode == 4 || mousecode == 1)
			while (++frac < 3)
				ft_zoom(x, y, SETUP.fract[frac]);
		else if (mousecode == 5 || mousecode == 2)
			while (++frac < 3)
				ft_dezoom(SETUP.fract[frac]);
	}
	return (1);
}
