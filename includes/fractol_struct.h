/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:32:54 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/03 18:14:07 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct		s_fract
{
	double			it;
	double			it_max;
	double			height_max;
	t_vec3			pos;
	t_vec3			vec;
	t_vec3			focus;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			zoom;
	double			tmp;
	t_color			**clr;
}					t_fract;

typedef struct		s_setup 
{
	size_t			width;
	size_t			height;
	size_t			ui;
	size_t			f_mode;
	t_mlx			*mlx;
	t_img			*img;
	t_fract			**fract;
}					t_setup;

#endif
