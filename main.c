/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 22:46:20 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/22 23:00:14 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main(int argc, char **argv)
{
	t_fo	*obj;

	if (argc == 2 && (ft_strcmp(argv[1], "mandelbrot") == 0 ||
		ft_strcmp(argv[1], "julia") == 0 || ft_strcmp(argv[1], "ship") == 0))
	{
		obj = fo_init(270 * 5, 240 * 5);
		if (ft_strcmp(argv[1], "mandelbrot") == 0)
			mlx_expose_hook(obj->win_ptr, fo_draw_mandelbrot, obj);
		else if (ft_strcmp(argv[1], "julia") == 0)
		{
			mlx_expose_hook(obj->win_ptr, fo_draw_julia, obj);
			mlx_hook(obj->win_ptr, 6, 0, fo_input_motion, obj);
		}
		else if (ft_strcmp(argv[1], "ship") == 0)
			mlx_expose_hook(obj->win_ptr, fo_draw_ship, obj);
		else
			fo_close(obj);
		mlx_hook(obj->win_ptr, 17, 0, fo_close, obj);
		mlx_key_hook(obj->win_ptr, fo_input_keyboard, obj);
		mlx_mouse_hook(obj->win_ptr, fo_input_mouse, obj);
		mlx_loop(obj->mlx_ptr);
	}
	else
		ft_putendl("Bad argument, type 'mandelbrot', 'julia' or 'ship'");
	return (0);
}
