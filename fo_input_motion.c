/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_input_motion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 03:19:14 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/22 22:52:56 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fo_input_motion(int x, int y, t_fo *obj)
{
	static double	old_xd = 0.0;
	static double	old_yd = 0.0;
	double			xd;
	double			yd;

	if (obj->fractal->type == JULIA && obj->fractal->morph == TRUE)
		if (x > 0 && x < (int)obj->win_width &&
			y > 0 && y < (int)obj->win_height)
		{
			xd = ((double)x - (double)obj->win_width / 2.0) /
				obj->fractal->zoom_x;
			yd = ((double)y - (double)obj->win_height / 2.0) /
				obj->fractal->zoom_y;
			obj->fractal->c.r += (xd - old_xd) / 10.0;
			obj->fractal->c.i += (yd - old_yd) / 10.0;
			old_xd = xd;
			old_yd = yd;
			fo_draw_julia(obj);
		}
	return (0);
}
