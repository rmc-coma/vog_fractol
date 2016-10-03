/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_draw_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 22:58:57 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/22 22:50:09 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_fractal	*fo_julia_init(t_fo *obj)
{
	t_fractal	*new;

	new = (t_fractal *)malloc(sizeof(t_fractal));
	new->type = JULIA;
	new->c.r = -0.7;
	new->c.i = 0.27015;
	new->x1 = -2.0;
	new->x2 = 2.0;
	new->y1 = -1.7777778;
	new->y2 = 1.7777778;
	new->max_i = 20;
	new->zoom_coeff = 1.0;
	new->morph = TRUE;
	obj->thr->running = 0;
	return (new);
}

static int			fo_col(t_size i, t_fo *obj)
{
	return ((i > obj->fractal->max_i / 3 ? i * 255 / obj->fractal->max_i : 0)
		* 255 / obj->fractal->max_i * 0x00010000 + (i > obj->fractal->max_i /
		2 ? i * 255 / obj->fractal->max_i : 0) * 255 / obj->fractal->max_i *
		0x00000100 + i * 255 / obj->fractal->max_i);
}

static void			fo_iterate_julia(t_size x, t_size y, t_fo *obj)
{
	t_size		i;
	t_cmpnbr	c;
	t_cmpnbr	z;
	t_cmpnbr	tmp;

	c = obj->fractal->c;
	z.r = (double)x / obj->fractal->zoom_x + obj->fractal->x1;
	z.i = (double)y / obj->fractal->zoom_y + obj->fractal->y1;
	i = 0;
	while (i < obj->fractal->max_i && z.r * z.r + z.i * z.i < 4)
	{
		tmp.r = z.r;
		tmp.i = z.i;
		z.r = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		z.i = 2 * tmp.r * tmp.i + c.i;
		++i;
	}
	if (i == obj->fractal->max_i)
		obj->frame->buffer[x + y * *(obj->frame->sizeline) / 4] = 0x00FFFFFF;
	else
		obj->frame->buffer[x + y * *(obj->frame->sizeline) / 4] =
			fo_col(i, obj);
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
			fo_iterate_julia(x, y, obj);
			++x;
		}
		++y;
	}
	pthread_exit(NULL);
}

int					fo_draw_julia(t_fo *obj)
{
	if (obj->fractal == NULL)
		obj->fractal = fo_julia_init(obj);
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
