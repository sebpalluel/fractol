/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:01:08 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/02 18:00:26 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_expose_hook(t_setup *setup)
{
	ft_imgclean(IMG, SETUP.width, SETUP.height);
	ft_fract_calc(setup);
	mlx_put_image_to_window(MLX->mlx_ptr, MLX->win_ptr, IMG->image, 0, 0);
	if (setup->ui == 1)
		ft_print(setup);
	mlx_do_sync(MLX->mlx_ptr);
	return (1);
}

static void ft_move_arrow_all(int keycode, float amp_x, float amp_y, \
		t_setup *setup)
{
	int		frac;

	frac = -1;
		if (keycode == LEFT)
			while (++frac < FNUM - 1)
			SETUP.fract[frac]->vec.x += amp_x;
		else if (keycode == RIGHT)
			while (++frac < FNUM - 1)
			SETUP.fract[frac]->vec.x -= amp_x;
		else if (keycode == UP)
			while (++frac < FNUM - 1)
			SETUP.fract[frac]->vec.y += amp_y;
		else if (keycode == DOWN)
			while (++frac < FNUM - 1)
			SETUP.fract[frac]->vec.y -= amp_y;
}

void	ft_move_arrow(int keycode, t_setup *setup)
{
	float	amp_x;
	float	amp_y;

	amp_x =  setup->width / (SETUP.fract[SETUP.f_mode]->zoom * \
			(setup->width / 10.));
	amp_y =  setup->height / (SETUP.fract[SETUP.f_mode]->zoom * \
			(setup->height / 10.));
	if (SETUP.f_mode < 3)
	{
		if (keycode == LEFT)
			SETUP.fract[SETUP.f_mode]->vec.x += amp_x;
		else if (keycode == RIGHT)
			SETUP.fract[SETUP.f_mode]->vec.x -= amp_x;
		else if (keycode == UP)
			SETUP.fract[SETUP.f_mode]->vec.y += amp_y;
		else if (keycode == DOWN)
			SETUP.fract[SETUP.f_mode]->vec.y -= amp_y;
	}
	else
		ft_move_arrow_all(keycode, amp_x, amp_y, setup);
}

static int	ft_key_hook(int keycode, t_setup *setup)
{
	if (keycode == ESC)
		ft_setup_mode(setup, 0);
	ft_switch_fract(keycode, setup);
	ft_change_color(keycode, setup);
	ft_move_arrow(keycode, setup);
	if (keycode == G_KEY)
		setup->ui = !setup->ui ? 1 : 0;
	ft_expose_hook(setup);
	return (0);
}

void		ft_mlx_process(t_setup *setup)
{
	mlx_key_hook(MLX->win_ptr, ft_key_hook, setup);
	mlx_expose_hook(MLX->win_ptr, ft_expose_hook, setup);
	mlx_hook(MLX->win_ptr, 6, (1L << 6), ft_mouse_moove, setup);
	mlx_mouse_hook(MLX->win_ptr, ft_mouse_hook, setup);
	mlx_do_sync(MLX->mlx_ptr);
	mlx_loop(MLX->mlx_ptr);
}

void	ft_put_pxl_to_img(t_setup *setup, t_vec3 pos, t_color *clr)
{
	unsigned int	index;

	index = (pos.y * setup->width) * (IMG->bbp >> 3) \
			+ pos.x * (IMG->bbp >> 3);
	if (pos.x < setup->width && pos.y < setup->height)
		ft_memcpy(setup->img->image_addr + index, clr, sizeof(int));
}
