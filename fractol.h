/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 22:44:29 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/22 22:51:19 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

# include <stdio.h>

# include "libft/include/libft.h"
# include "libft/include/get_next_line.h"
# include "minilibx/mlx.h"

# define FALSE		0
# define TRUE		!FALSE
# define SUCCESS	0
# define FAILURE	!SUCESS

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_TILD	50

# define MANDELBROT	0
# define JULIA		1
# define SHIP		2

typedef unsigned int	t_size;
typedef unsigned char	t_bool;

typedef struct			s_threads
{
	t_size		running;
	t_bool		lock;
	pthread_t	*core1;
	pthread_t	*core2;
	pthread_t	*core3;
	pthread_t	*core4;
}						t_threads;

typedef struct			s_cmpnbr
{
	double		r;
	double		i;
}						t_cmpnbr;

typedef struct			s_fractal
{
	int			type;
	t_cmpnbr	c;
	t_size		max_i;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		zoom_x;
	double		zoom_y;
	double		zoom_coeff;
	t_bool		morph;
}						t_fractal;

typedef struct			s_frame
{
	void		*img_ptr;
	int			*buffer;
	int			*bpp;
	int			*sizeline;
	int			*endian;
}						t_frame;

typedef struct			s_fo
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_size		win_height;
	t_size		win_width;
	t_frame		*frame;
	t_fractal	*fractal;
	t_threads	*thr;
}						t_fo;

t_fo					*fo_init(t_size win_width, t_size win_height);
int						fo_close(t_fo *obj);
int						fo_draw_mandelbrot(t_fo *obj);
int						fo_draw_julia(t_fo *obj);
int						fo_draw_ship(t_fo *obj);
void					fo_clear_framebuffer(t_fo *obj);
int						fo_input_keyboard(int keycode, t_fo *obj);
int						fo_input_mouse(int button, int x, int y, t_fo *obj);
int						fo_input_motion(int x, int y, t_fo *obj);
void					fo_fireup_threads(t_fo *obj, void *(*f)(void *));

#endif
