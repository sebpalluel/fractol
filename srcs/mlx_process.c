/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:01:08 by psebasti          #+#    #+#             */
/*   Updated: 2017/06/23 13:50:00 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_expose_hook(void *param)
{
	t_setup *setup;

	setup = param;
	printf("test expose hook\n");
	ft_imgclean(IMG, SETUP.width, SETUP.height);
	//mlx_put_image_to_window(MLX->mlx_ptr, MLX->win_ptr, IMG->image, 0, 0);
	mlx_put_image_to_window(MLX->mlx_ptr, MLX->win_ptr, \
			IMG->image, 0, 0);
	//	if (setup->ui == 1)
	//		ft_print_cam(setup);
	printf("test expose hook end\n");
	ft_fract_calc(setup);
	mlx_do_sync(MLX->mlx_ptr);
	return (1);
}

static int	ft_key_hook(int keycode, void *param)
{
	t_setup *setup;

	setup = param;
	printf("test key hook %d param %p\n", keycode, setup);
	if (keycode == ESC)
		ft_setup_mode(0, setup, 0);
	//	//ft_scale_cam(setup, keycode);
	//	//ft_rot_cam(setup, keycode);
	//	//ft_orient_cam(setup, keycode);
	//	if (keycode == G_KEY)
	//		setup->ui = !setup->ui ? 1 : 0;
	ft_expose_hook(setup);
	//	//printf("mlx_key_hook %d\n", keycode);
	return (0);
}

void		ft_mlx_process(t_setup *setup)
{
	printf("mlx_process begin, win_ptr %p setup %p\n", MLX->win_ptr, setup);
	mlx_key_hook(MLX->win_ptr, ft_key_hook, setup);
	printf("mlx_process before expose\n");
	mlx_expose_hook(MLX->win_ptr, ft_expose_hook, setup);
	mlx_mouse_hook(MLX->win_ptr, ft_mouse_hook, setup);
	printf("mlx_process after expose\n");
	//		ft_fract_calc(setup);
	//	if (mlx_key_hook(MLX->win_ptr, ft_key_hook, setup[0]) == ESC)
	//	{
	//		printf("mlx_process delete\n");
	//		ft_setup_mode(0, setup, 0);
	//	}
	mlx_do_sync(MLX->mlx_ptr);
	printf("mlx_process after sync\n");
	mlx_loop(MLX->mlx_ptr);
}

void	ft_put_pxl_to_img(t_setup *setup, t_fract *fract, t_color *clr)
{
	if (fract->x < setup->width && fract->y < setup->height)
		ft_memcpy(setup->img->image_addr + \
				(int)(4 * WIDTH * fract->y + fract->x * 4), clr, sizeof(int));
}
