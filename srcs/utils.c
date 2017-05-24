/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:50:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/24 15:16:04 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_pthread_process(t_setup **setup, void *(*f)(void *))
{
	pthread_t	thread[NUM_THREAD];
	int			i;
	int			err;

	i = 0;
	while (i < NUM_THREAD)
	{
		if ((err = pthread_create(&thread[i], NULL, f, &setup[0][i + 1])) != 0)
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

int				ft_fractol_pthread(t_setup **setup, size_t frac, \
		void *(*f)(void *))
{
	int			err;
	size_t		i;
	size_t		j;

	i = 1;
	j = 0;

	while (i < NUM_THREAD + 1)
	{
		ft_memcpy((void *)setup[0][i].fract[frac], (void *)SETUP.fract[frac],\
				sizeof(t_fract));
		while (j < 3)
		{	
			ft_memcpy((void *)setup[0][i].fract[frac]->clr[j], \
					(void *)SETUP.fract[frac]->clr[j], sizeof(t_color));
			j++;
		}
		setup[0][i].fract[frac]->y = 100 * i;
		setup[0][i].fract[frac]->y_max = 100 * (i + 1);
		i++;
	}
	err = ft_pthread_process(setup, f);
	mlx_put_image_to_window(SETUP.mlx->mlx_ptr, MLX->win_ptr, \
			IMG->image_addr, 0, 0);
	return (err);
}
