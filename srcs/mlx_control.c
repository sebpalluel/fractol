/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:19:33 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/12 15:17:54 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		ft_form_fract(int keycode, t_setup *setup)
{
	int		frac;

	frac = -1;
	if (SETUP.f_mode < FNUM - 1)
	{
		if (keycode == MINUS && SETUP.fract[SETUP.f_mode]->it_max > 10)
			SETUP.fract[SETUP.f_mode]->it_max -= 10;
		if (keycode == EQUAL && SETUP.fract[SETUP.f_mode]->it_max < 250)
			SETUP.fract[SETUP.f_mode]->it_max += 10;
	}
	if (SETUP.f_mode == FNUM)
	{
		if (keycode == MINUS)
			while (++frac < FNUM && SETUP.fract[frac]->it_max > 10)
				SETUP.fract[frac]->it_max -= 10;
		if (keycode == EQUAL)
			while (++frac < FNUM && SETUP.fract[frac]->it_max < 250)
				SETUP.fract[frac]->it_max += 10;
	}
}

void		ft_switch_fract(int keycode, t_setup *setup)
{
	if (keycode == ONE)
		SETUP.f_mode = 0;
	if (keycode == TWO)
		SETUP.f_mode = 1;
	if (keycode == THREE)
		SETUP.f_mode = 2;
	if (keycode == FOUR)
		SETUP.f_mode = 3;
	if (keycode == ZERO)
		SETUP.f_mode = 4;
}

void		ft_change_color(int keycode, int f_mode, t_setup *setup)
{
	if (keycode == Q_KEY && SETUP.fract[f_mode]->clr[0]->r > 0)
		SETUP.fract[f_mode]->clr[0]->r -= 5;
	if (keycode == A_KEY && SETUP.fract[f_mode]->clr[0]->g > 0)
		SETUP.fract[f_mode]->clr[0]->g -= 5;
	if (keycode == Z_KEY && SETUP.fract[f_mode]->clr[0]->b > 0)
		SETUP.fract[f_mode]->clr[0]->b -= 5;
	if (keycode == W_KEY && SETUP.fract[f_mode]->clr[0]->r < 255)
		SETUP.fract[f_mode]->clr[0]->r += 5;
	if (keycode == S_KEY && SETUP.fract[f_mode]->clr[0]->g < 255)
		SETUP.fract[f_mode]->clr[0]->g += 5;
	if (keycode == X_KEY && SETUP.fract[f_mode]->clr[0]->b < 255)
		SETUP.fract[f_mode]->clr[0]->b += 5;
	if (keycode == E_KEY && SETUP.fract[f_mode]->clr[1]->r > 0)
		SETUP.fract[f_mode]->clr[1]->r -= 5;
	if (keycode == D_KEY && SETUP.fract[f_mode]->clr[1]->g > 0)
		SETUP.fract[f_mode]->clr[1]->g -= 5;
	if (keycode == C_KEY && SETUP.fract[f_mode]->clr[1]->b > 0)
		SETUP.fract[f_mode]->clr[1]->b -= 5;
	if (keycode == R_KEY && SETUP.fract[f_mode]->clr[1]->r < 255)
		SETUP.fract[f_mode]->clr[1]->r += 5;
	if (keycode == F_KEY && SETUP.fract[f_mode]->clr[1]->g < 255)
		SETUP.fract[f_mode]->clr[1]->g += 5;
	if (keycode == V_KEY && SETUP.fract[f_mode]->clr[1]->b < 255)
		SETUP.fract[f_mode]->clr[1]->b += 5;
}
