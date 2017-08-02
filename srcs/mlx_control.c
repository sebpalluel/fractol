/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:19:33 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/02 16:34:05 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//static void	ft_print_color(t_setup *setup)
//{	
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16711680,
//			" key Q/W   LERP_IN R:");
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 5, 0, 16711680,
//			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[0]->r)));
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 20, 65280,
//			" key A/S   LERP_IN G:");
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 5, 20, 65280,
//			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[0]->g)));
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 40, 255,
//			" key Z/X   LERP_IN B:");
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 5, 40, 255,
//			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[0]->b)));
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 4, 0, 16711680,
//			" key E/R   LERP_OUT R:");
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 2.15, 0, 16711680,
//			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[1]->r)));
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 4, 20, 65280,
//			" key D/F   LERP_OUT G:");
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 2.15, 20, 652805,
//			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[1]->g)));
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 4, 40, 255,
//			" key C/V   LERP_OUT B:");
//	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 2.15, 40, 255,
//			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[1]->b)));
//}

static void	ft_print_fract_info(t_setup *setup)
{
	if (SETUP.f_mode == 0)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215,
			" mandelbrot");
	if (SETUP.f_mode == 1)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215,
			" julia");
	if (SETUP.f_mode == 2)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215,
			" cantor");
	if (SETUP.f_mode == 3)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215,
			" burningship");
	if (SETUP.f_mode == 4)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215,
			" all");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 20, 16777215,
			" iteration : ");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 8, 20, 16777215,
			ft_ftoa(SETUP.fract[SETUP.f_mode]->it_max));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 40, 16777215,
			" pos x/y : ");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 8, 40, 16777215,
			ft_ftoa(SETUP.fract[SETUP.f_mode]->vec.x));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 4, 40, 16777215,
			ft_ftoa(SETUP.fract[SETUP.f_mode]->vec.y));
}

void		ft_print(t_setup *setup)
{
	ft_print_fract_info(setup);
	//ft_print_color(setup);
}

void	ft_change_color(int keycode, t_setup *setup)
{
	if (keycode == Q_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->r > 0)
		SETUP.fract[SETUP.f_mode]->clr[0]->r -= 5;
	if (keycode == A_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->g > 0)
		SETUP.fract[SETUP.f_mode]->clr[0]->g -= 5;
	if (keycode == Z_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->b > 0)
		SETUP.fract[SETUP.f_mode]->clr[0]->b -= 5;
	if (keycode == W_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->r < 255)
		SETUP.fract[SETUP.f_mode]->clr[0]->r += 5;
	if (keycode == S_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->g < 255)
		SETUP.fract[SETUP.f_mode]->clr[0]->g += 5;
	if (keycode == X_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->b < 255)
		SETUP.fract[SETUP.f_mode]->clr[0]->b += 5;
	if (keycode == E_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->r > 0)
		SETUP.fract[SETUP.f_mode]->clr[1]->r -= 5;
	if (keycode == D_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->g > 0)
		SETUP.fract[SETUP.f_mode]->clr[1]->g -= 5;
	if (keycode == C_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->b > 0)
		SETUP.fract[SETUP.f_mode]->clr[1]->b -= 5;
	if (keycode == R_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->r < 255)
		SETUP.fract[SETUP.f_mode]->clr[1]->r += 5;
	if (keycode == F_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->g < 255)
		SETUP.fract[SETUP.f_mode]->clr[1]->g += 5;
	if (keycode == V_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->b < 255)
		SETUP.fract[SETUP.f_mode]->clr[1]->b += 5;
}


