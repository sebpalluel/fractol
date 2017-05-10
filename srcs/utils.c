/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:50:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/10 18:54:14 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_pthread_process(t_setup tab[NUM_THREAD], void *(*f)(void *))
{
	pthread_t	thread[NUM_THREAD];
	int			i;
	int			err;

	i = 0;
	while (i < NUM_THREAD)
	{
		if ((err = pthread_create(&thread[i], NULL, f, &tab[i])) != 0)
			return (err);
		printf("fract process %f test %f\n", tab[i].fract[0].y, tab[i].test);
		i++;
	}
	while (i > 0)
	{
		i--;
		printf("i %d\n", i);
		if ((err = pthread_join(thread[i], NULL)) != 0)
			return (err);
	}
	return (err);
}

static void		ft_pthread_memcpy(t_setup tab[NUM_THREAD], t_setup *setup, \
		size_t i)
{
	ft_memcpy((void *)&tab[i], (void *)setup, sizeof(t_setup));
	ft_memcpy((void *)tab[i].mlx, (void *)setup->mlx, sizeof(t_mlx));
	ft_memcpy((void *)tab[i].map, (void *)setup->map, sizeof(t_map));
	ft_memcpy((void *)tab[i].cam, (void *)setup->cam, sizeof(t_cam));
	ft_memcpy((void *)tab[i].img, (void *)setup->img, sizeof(t_img));
	ft_memcpy((void *)tab[i].fract, (void *)setup->fract, sizeof(t_fract));
}

int				ft_fractol_pthread(t_setup *setup, size_t frac, \
		void *(*f)(void *))
{
	t_setup		tab[NUM_THREAD];
	int			err;
	size_t		i;

	i = 0;
	while (i < NUM_THREAD)
	{
		ft_pthread_memcpy(tab, setup, i);
		tab[i].fract[frac].y = 100 * i;
		tab[i].test = 100 * i;
		printf("fract tmp %f test %f\n", tab[i].fract[frac].y, tab[i].test);
		tab[i].fract[frac].y_max = 100 * (i + 1);
		i++;
	}
	err = ft_pthread_process(tab, f);
	mlx_put_image_to_window(setup->mlx, MLX->win_ptr, IMG->image_addr, 1, 0);
	return (err);
}
