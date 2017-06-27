/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:25:18 by psebasti          #+#    #+#             */
/*   Updated: 2017/06/27 14:53:52 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libs/libft/includes/libft.h"
# include "../includes/fractol_struct.h"
# include "../includes/fractol_define.h"
# include <stdio.h>

int		ft_error_usage();
size_t	ft_setup_mode(t_setup *setup, size_t mode);
int		ft_fractol_pthread(t_setup *setup, size_t frac, void *(*f)(void *));
void	ft_mlx_process(t_setup *setup);
void	ft_put_pxl_to_img(t_setup *setup, t_fract *fract, t_color *clr);
void	ft_mandelbrot_init(t_setup *setup);
void	*ft_mandelbrot(void *setup);
t_color	*ft_mandelbrot_give_color(t_setup *setup);
void	ft_julia_init(t_setup *setup);
void	*ft_julia(void *setup);
t_color	*ft_julia_give_color(t_setup *setup);
size_t	ft_fract_calc(t_setup *setup);
int		ft_mouse_hook(int mousecode, int x, int y, t_setup *param);

#endif
