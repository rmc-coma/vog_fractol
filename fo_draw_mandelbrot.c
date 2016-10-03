/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_draw_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 22:58:57 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/22 22:39:29 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractal	*fo_mandelbrot_init(t_fo *obj)
{
	t_fractal	*new;

	new = (t_fractal *)malloc(sizeof(t_fractal));
	new->type = MANDELBROT;
	new->x1 = -2.1;
	new->x2 = 0.6;
	new->y1 = -1.2;
	new->y2 = 1.2;
	new->max_i = 40;
	new->zoom_coeff = 1.0;
	obj->thr->running = 0;
	return (new);
}

static void			fo_iterate_mandelbrot(t_size x, t_size y, t_fo *obj)
{
	t_size		i;
	t_cmpnbr	c;
	t_cmpnbr	z;
	double		tmp;

	c.r = (double)x / obj->fractal->zoom_x + obj->fractal->x1;
	c.i = (double)y / obj->fractal->zoom_y + obj->fractal->y1;
	z.r = 0.0;
	z.i = 0.0;
	i = 0;
	while (i < obj->fractal->max_i && z.r * z.r + z.i * z.i < 4)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		++i;
	}
	if (i == obj->fractal->max_i)
		obj->frame->buffer[x + y * *(obj->frame->sizeline) / 4] = 0x00FFFFFF;
	else
		obj->frame->buffer[x + y * *(obj->frame->sizeline) / 4] = i * 255 /
			obj->fractal->max_i;
}

static void			*fo_draw_part(void *arg)
{
	t_fo		*obj;
	t_size		x;
	t_size		y;
	t_size		y_max;

	obj = (t_fo *)arg;
	y = obj->thr->running * lround((double)obj->win_height / 4.0);
	obj->thr->lock = FALSE;
	y_max = y + lround((double)obj->win_height / 4.0);
	while (y < y_max)
	{
		x = 0;
		while (x < obj->win_width)
		{
			fo_iterate_mandelbrot(x, y, obj);
			++x;
		}
		++y;
	}
	pthread_exit(NULL);
}

int					fo_draw_mandelbrot(t_fo *obj)
{
	if (obj->fractal == NULL)
		obj->fractal = fo_mandelbrot_init(obj);
	mlx_clear_window(obj->mlx_ptr, obj->win_ptr);
	fo_clear_framebuffer(obj);
	obj->fractal->zoom_x = (obj->win_width /
		(obj->fractal->x2 - obj->fractal->x1)) * obj->fractal->zoom_coeff;
	obj->fractal->zoom_y = (obj->win_height /
		(obj->fractal->y2 - obj->fractal->y1)) * obj->fractal->zoom_coeff;
	fo_fireup_threads(obj, fo_draw_part);
	mlx_put_image_to_window(obj->mlx_ptr, obj->win_ptr,
							obj->frame->img_ptr, 0, 0);
	return (0);
}
