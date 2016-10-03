/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_input_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 02:13:14 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/22 02:39:03 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fo_zoom_in(int x, int y, t_fo *obj)
{
	double			xd;
	double			yd;
	static t_size	i = 0;

	obj->fractal->zoom_coeff *= 1.05;
	xd = (double)x / obj->fractal->zoom_x;
	yd = (double)y / obj->fractal->zoom_y;
	obj->fractal->x1 += xd;
	obj->fractal->x2 += xd;
	obj->fractal->y1 += yd;
	obj->fractal->y2 += yd;
	i++;
	if (i == 5)
	{
		obj->fractal->max_i += 1;
		i = 0;
	}
}

static void	fo_zoom_out(int x, int y, t_fo *obj)
{
	double			xd;
	double			yd;
	static t_size	i = 0;

	obj->fractal->zoom_coeff *= 1.0 / 1.05;
	xd = ((double)x - 67.5) / obj->fractal->zoom_x;
	yd = ((double)y - 61.0) / obj->fractal->zoom_y;
	obj->fractal->x1 += xd;
	obj->fractal->x2 += xd;
	obj->fractal->y1 += yd;
	obj->fractal->y2 += yd;
	i++;
	if (i == 5)
	{
		if (obj->fractal->max_i > 1)
			obj->fractal->max_i += 1;
		i = 0;
	}
}

int			fo_input_mouse(int buttoncode, int x, int y, t_fo *obj)
{
	if (x > 0 && x < (int)obj->win_width &&
		y > 0 && y < (int)obj->win_height)
	{
		if (buttoncode == 1 || buttoncode == 4)
			fo_zoom_in(x - obj->win_width / 2, y - obj->win_height / 2, obj);
		else if (buttoncode == 2 || buttoncode == 5)
			fo_zoom_out(x - obj->win_width / 2, y - obj->win_height / 2, obj);
		else
			return (0);
		if (obj->fractal->type == MANDELBROT)
			fo_draw_mandelbrot(obj);
		else if (obj->fractal->type == JULIA)
			fo_draw_julia(obj);
		else if (obj->fractal->type == SHIP)
			fo_draw_ship(obj);
	}
	return (0);
}
