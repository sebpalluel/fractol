/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:50:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/11 18:08:56 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_pthread_process(t_setup *setup, void *(*f)(void *))
{
	pthread_t	thread[NUM_THREAD];
	int			i;
	int			err;

	i = 0;
	while (i < NUM_THREAD)
	{
		if ((err = pthread_create(&thread[i], NULL, f, &setup[i + 1])) != 0)
			return (err);
	//	printf("fract process %f it_max %f\n", setup[i + 1].fract[0]->y\
	//			, setup[i + 1].fract[0]->it_max);
		printf("i before %d\n", i);
		i++;
	}
	while (i > 0)
	{
		i--;
		printf("i after %d\n", i);
		if ((err = pthread_join(thread[i], NULL)) != 0)
		{
			printf("err %d\n", err);
			return (err);
		}
	}
	printf("err end %d\n", err);
	return (err);
}

int				ft_fractol_pthread(t_setup *setup, size_t frac, \
		void *(*f)(void *))
{
	int			err;
	size_t		i;

	i = 1;
	while (i < NUM_THREAD + 1)
	{
		printf("i fractol_pthread %lu\n", i);
		ft_memcpy((void *)setup[i].fract[frac], (void *)SETUP.fract[frac], sizeof(t_fract));
		setup[i].fract[frac]->y = 100 * i;
		setup[i].fract[frac]->y_max = 100 * (i + 1);
		i++;
	}
	err = ft_pthread_process(setup, f);
	mlx_put_image_to_window(setup->mlx, MLX->win_ptr, IMG->image_addr, 1, 0);
	return (err);
}
