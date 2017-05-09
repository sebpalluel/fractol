/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:50:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/09 18:20:30 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_pthread_process(t_setup *tab, void *(*f)(void *))
{
	pthread_t	thread[NUM_THREAD];
	int			i;
	int			err;

	i = 0;
	while (i < NUM_THREAD)
	{
		if ((err = pthread_create(&thread[i], NULL, f, &tab[i])) != 0)
			return (err);
	printf("fract tmp %f\n", tab[i].fract[0]->y);
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

int				ft_fractol_pthread(t_setup *setup, size_t frac, \
		void *(*f)(void *))
{
	t_setup		*tab;
	int			err;
	size_t		i;

	i = 0;
	ft_tabnew();
	if (!(tab = (t_setup *)ft_memalloc(sizeof(t_setup) * NUM_THREAD)))
		return (-1);
	while (i < NUM_THREAD)
	{
		ft_memcpy((void*)&tab[i], (void*)setup, sizeof(t_setup));
		tab[i].fract[frac]->y = 100 * i;
		//printf("fract tmp %f\n", tab[i].fract[frac]->y);
		tab[i].fract[frac]->y_max = 100 * (i + 1);
		i++;
	}
	err = ft_pthread_process(tab, f);
	mlx_put_image_to_window(setup->mlx, MLX->win_ptr, IMG->image_addr, 1, 0);
	return (err);
}
