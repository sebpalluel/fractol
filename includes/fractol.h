/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:25:18 by psebasti          #+#    #+#             */
/*   Updated: 2017/04/18 20:56:19 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/libft/includes/libft.h"
# include "../includes/fractol_struct.h"
# include "../includes/fractol_define.h"

size_t	ft_setup_mode(int ac, char **av, t_setup *setup, size_t mode);
size_t	ft_setup_init(t_setup *setup);
void	ft_mlx_process(t_setup *setup);
size_t	ft_mandelbrot_init(t_setup *setup);
size_t	ft_julia_init(t_setup *setup);
size_t	ft_mandelbrot_pthread(t_setup *setup);
size_t	ft_julia_pthread(t_setup *setup);
size_t	ft_fract_calc(t_setup *setup);
int		ft_mouse_hook(int mousecode, int x, int y, t_setup *setup);

#endif
