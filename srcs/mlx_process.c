/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:01:08 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/25 19:15:42 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_expose_hook(t_setup *setup)
{
//	ft_imgclean(IMG, SETUP.width, SETUP.height);
//	ft_fract_calc(setup);
	mlx_put_image_to_window(MLX->mlx_ptr, MLX->win_ptr, IMG->image, 0, 0);
	//	if (setup->ui == 1)
	//		ft_print_cam(setup);
	mlx_do_sync(MLX->mlx_ptr);
	return (1);
}

static int	ft_key_hook(int keycode, t_setup *setup)
{

	//printf("test key hook %d param %p\n", keycode, setup);
	if (keycode == ESC)
		ft_setup_mode(setup, 0);
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
	mlx_key_hook(MLX->win_ptr, ft_key_hook, setup);
	mlx_expose_hook(MLX->win_ptr, ft_expose_hook, setup);
	mlx_mouse_hook(MLX->win_ptr, ft_mouse_hook, setup);
	mlx_do_sync(MLX->mlx_ptr);
	mlx_loop(MLX->mlx_ptr);
}

void	ft_put_pxl_to_img(t_setup *setup, t_vec3 pos, t_color *clr)
{
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	unsigned int	index;

	pthread_mutex_lock (&mutex);
	index = (pos.y * setup->width) * (IMG->bbp >> 3) \
			+ pos.x * (IMG->bbp >> 3);
	if (pos.x < setup->width && pos.y < setup->height)
		ft_memcpy(setup->img->image_addr + index, clr, sizeof(int));
	pthread_mutex_unlock(&mutex);
}
