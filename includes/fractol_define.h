/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_define.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:31:26 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/01 18:49:08 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_DEFINE_H
# define FRACTOL_DEFINE_H

# define WIDTH		1080
# define HEIGHT		1080
# define NUM_THREAD	8
# define FNUM		4
# define AMP		1.3

# define ERROR		1
# define OK			0

# define SETUP		setup[0]
# define MAN		setup->fract[0]
# define JUL		setup->fract[1]
# define CAN		setup->fract[2]
# define BUR		setup->fract[3]
# define MAP		setup->map
# define M_WIDTH	setup->map->width
# define M_HEIGHT	setup->map->height
# define M_DEPTH	setup->map->depth
# define LERP_IN	setup->map->lerp_in
# define LERP_OUT	setup->map->lerp_out
# define CLR		setup->map->curr_clr
# define CAM		setup->cam
# define MLX		setup->mlx
# define IMG		setup->img

#endif
