/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:01:08 by psebasti          #+#    #+#             */
/*   Updated: 2017/04/14 18:29:18 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_expose_hook(t_setup *setup)
{
	ft_imgclean(IMG, setup->width, setup->height);
	mlx_put_image_to_window(MLX->mlx_ptr, MLX->win_ptr, IMG->image, 0, 0);
//	if (setup->ui == 1)
//		ft_print_cam(setup);
	mlx_do_sync(MLX->mlx_ptr);
	return (0);
}

static int	ft_key_hook(int keycode, t_setup *setup)
{
	if (keycode == ESC)
		ft_setup_mode(0, NULL, setup, 0);
	//ft_scale_cam(setup, keycode);
	//ft_rot_cam(setup, keycode);
	//ft_orient_cam(setup, keycode);
	if (keycode == G_KEY)
		setup->ui = !setup->ui ? 1 : 0;
	//ft_update_map_and_cam(setup);
	ft_expose_hook(setup);
	//printf("mlx_key_hook %d\n", keycode);
	return (0);
}

void		ft_mlx_process(t_setup *setup)
{
	//ft_update_map_and_cam(setup);
	mlx_key_hook(MLX->win_ptr, ft_key_hook, setup);
	mlx_expose_hook(MLX->win_ptr, ft_expose_hook, setup);
	mlx_do_sync(MLX->mlx_ptr);
	mlx_loop(MLX->mlx_ptr);
}
