/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:50:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/05 18:57:29 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_pthread_process(t_setup tab[NUM_THREAD], void *(*f)(void *))
{
	pthread_t	thread[NUM_THREAD];
	size_t		i;
	int			err;
	
	i = 0;
	while (i < NUM_THREAD)
	{
		if ((err = pthread_create(&thread[i], NULL, f, &tab[i])) != 0)
			return (err);
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

int				ft_fractol_pthread(t_setup *setup, size_t frac, \
		void *(*f)(void *))
{
	t_setup		tab[NUM_THREAD];
	int			err;
	int			i;

	i = 0;
	while (i < NUM_THREAD)
	{
		ft_memcpy((void*)&tab[i], (void*)setup, sizeof(t_setup));
		tab[i].fract[frac]->y = 100 * i;
		tab[i].fract[frac]->y_max = 100 * (i + 1);
		i++;
	}
	err = ft_pthread_process(tab, f);
	mlx_put_image_to_window(setup->mlx, MLX->win_ptr, IMG->image_addr, 1, 0);
	return (err);
}
