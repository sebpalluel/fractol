/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:50:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/05 16:43:17 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int				ft_fractol_pthread(t_setup *setup, void *(*f)(void *))
{
	t_fract		tab[NUM_THREAD];
	pthread_t	thread[NUM_THREAD];
	int			err;
	int			i;

	i = 0;
	while (i < NUM_THREAD)
	{
		ft_memcpy((void*)&tab[i], (void*)setup, sizeof(t_setup));
		tab[i].y = 100 * i;
		tab[i].y_max = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= NUM_THREAD)
		if ((err = pthread_create(&thread[i - 1], NULL, f, &tab[i - 1])) != 0)
			return (err);
	while (i--)
		if ((err = pthread_join(thread[i], NULL)) != 0)
			return (err);
	mlx_put_image_to_window(setup->mlx, MLX->win_ptr, IMG->image_addr, 1, 0);
	return (err);
}
