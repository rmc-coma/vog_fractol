/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_input_keyboard.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 01:19:12 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/22 22:52:19 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	fo_draw_current(t_fo *obj)
{
	if (obj->fractal->type == MANDELBROT)
		fo_draw_mandelbrot(obj);
	else if (obj->fractal->type == JULIA)
		fo_draw_julia(obj);
	else if (obj->fractal->type == SHIP)
		fo_draw_ship(obj);
}

static void	fo_strafe(int keycode, t_fo *obj)
{
	if (keycode == KEY_A)
	{
		obj->fractal->x2 -= 0.05 / obj->fractal->zoom_coeff;
		obj->fractal->x1 -= 0.05 / obj->fractal->zoom_coeff;
	}
	else if (keycode == KEY_D)
	{
		obj->fractal->x2 += 0.05 / obj->fractal->zoom_coeff;
		obj->fractal->x1 += 0.05 / obj->fractal->zoom_coeff;
	}
	else
		return ;
}

static void	fo_elevate(int keycode, t_fo *obj)
{
	if (keycode == KEY_S)
	{
		obj->fractal->y2 += 0.05 / obj->fractal->zoom_coeff;
		obj->fractal->y1 += 0.05 / obj->fractal->zoom_coeff;
	}
	else if (keycode == KEY_W)
	{
		obj->fractal->y2 -= 0.05 / obj->fractal->zoom_coeff;
		obj->fractal->y1 -= 0.05 / obj->fractal->zoom_coeff;
	}
	else
		return ;
}

int			fo_input_keyboard(int keycode, t_fo *obj)
{
	if (keycode == KEY_ESC)
		fo_close(obj);
	else
	{
		if (keycode == KEY_A || keycode == KEY_D)
			fo_strafe(keycode, obj);
		else if (keycode == KEY_W || keycode == KEY_S)
			fo_elevate(keycode, obj);
		else if (obj->fractal->type == JULIA && keycode == KEY_TILD)
			obj->fractal->morph = !obj->fractal->morph;
		else
			return (0);
		fo_draw_current(obj);
	}
	return (0);
}
