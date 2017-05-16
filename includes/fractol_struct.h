/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:32:54 by psebasti          #+#    #+#             */
/*   Updated: 2017/05/11 16:50:58 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

typedef struct		s_map
{
	int				width;
	int				height;
	t_color			*lerp_in;
	t_color			*lerp_out;
	t_color			*curr_clr;
	t_pix			*pix;
	t_pix			**map;
}					t_map;

typedef struct		s_cam
{
	t_vec3			*pos;
	t_vec3			*rot;
	double			scale;
	double			fov;
	double			offset_x;
	double			offset_y;
}					t_cam;

typedef struct		s_fract
{
	double			it;
	double			it_max;
	double			y_max;
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			zoom;
	double			tmp;
	t_color			*clr_tmp;
	t_color			*lerp_in;
	t_color			*lerp_out;
}					t_fract;

typedef struct		s_setup 
{
	size_t			width;
	size_t			height;
	size_t			ui;
	size_t			f_mode;
	t_mlx			*mlx;
	//t_map			*map;
	//t_cam			*cam;
	t_img			*img;
	t_fract			**fract;
}					t_setup;

#endif
