/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:09:10 by psebasti          #+#    #+#             */
/*   Updated: 2017/04/14 18:23:35 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			main(int ac, char **av)
{
	t_setup	*setup = NULL;

	if (!(setup = (t_setup *)malloc(sizeof(t_setup))))
		return (-1);
	if (ft_setup_mode(ac, av, setup, 1) && ft_setup_init(setup))
		ft_mlx_process(setup);
	return (ft_setup_mode(ac, av, setup, 0));
}
