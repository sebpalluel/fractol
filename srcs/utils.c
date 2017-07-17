/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:50:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/13 22:27:11 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_pthread_process(t_setup *setup, void *(*f)(void *))
{
	pthread_t	thread[NUM_THREAD];
	int			i;
	int			err;

	i = 0;
	err = 0;
	while (i < NUM_THREAD)
	{
		if ((err = pthread_create(&thread[i], NULL, f, &setup[i + 1])) != 0)
			return (err);
		f(&setup[i + 1]);
		i++;
	}
	while (i > 0)
	{
		i--;
		if ((err = pthread_join(thread[i], NULL)) != 0)
			return (err);
	}
	return (err);
}

static void		ft_fractol_cpy(t_setup *setup, size_t frac, size_t i)
{
	size_t		j;

	setup[i + 1].fract[frac]->it_max = SETUP.fract[frac]->it_max;
	setup[i + 1].fract[frac]->zoom = SETUP.fract[frac]->zoom;
	ft_vec3cpy(&SETUP.fract[frac]->pos, &setup[i + 1].fract[frac]->pos);
	ft_vec3cpy(&SETUP.fract[frac]->vec, &setup[i + 1].fract[frac]->vec);
	ft_vec3cpy(&SETUP.fract[frac]->focus, &setup[i + 1].fract[frac]->focus);
	j = 0;
	while (j < 3)
	{	
		ft_colorcpy(SETUP.fract[frac]->clr[j], \
				setup[i + 1].fract[frac]->clr[j]);
		//printf("SETUP col %p, setup[%lu] col %p \n",SETUP.fract[frac]->clr[j], \
		//		i + 1, setup[i + 1].fract[frac]->clr[j]);
		j++;
	}
}

int				ft_fractol_pthread(t_setup *setup, size_t frac, \
		void *(*f)(void *))
{
	int			err;
	size_t		i;
	size_t		inc;

	i = 0;
	inc = setup->height / NUM_THREAD;
	printf("\n\n\n");
	while (i < NUM_THREAD)
	{
		ft_fractol_cpy(setup, frac, i);
		printf("setup fract %p, SETUP fract %p\n",setup[i + 1].fract[frac], SETUP.fract[frac]);
		setup[i + 1].fract[frac]->pos.y = inc * i;
		setup[i + 1].fract[frac]->height_max = inc * (i + 1);
		//	printf("fract->y %f fract->height_max %f\n", setup[i + 1].fract[frac]->pos.y, \
		//			setup[i + 1].fract[frac]->height_max);
			printf("test color thread r %d\n", setup[i + 1].fract[frac]->clr[2]->r);
			printf("test color main r %d\n", setup[0].fract[frac]->clr[2]->r);
		i++;
	}
	err = ft_pthread_process(setup, f);
	return (err);
}
