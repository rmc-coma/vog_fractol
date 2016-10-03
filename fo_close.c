/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 06:04:51 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/22 02:43:07 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fo_close(t_fo *obj)
{
	free(obj->thr->core1);
	free(obj->thr->core2);
	free(obj->thr->core3);
	free(obj->thr->core4);
	free(obj->thr);
	free(obj->fractal);
	mlx_clear_window(obj->mlx_ptr, obj->win_ptr);
	mlx_destroy_image(obj->mlx_ptr, obj->frame->img_ptr);
	free(obj->frame->bpp);
	free(obj->frame->sizeline);
	free(obj->frame->endian);
	free(obj->frame);
	mlx_destroy_window(obj->mlx_ptr, obj->win_ptr);
	free(obj);
	exit(EXIT_SUCCESS);
	return (0);
}
