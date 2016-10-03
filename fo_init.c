/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 22:51:04 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/19 22:42:00 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fo	*fo_init(t_size win_width, t_size win_height)
{
	t_fo	*new;

	new = (t_fo *)malloc(sizeof(t_fo));
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, win_width, win_height,
								"Fractol");
	new->win_width = win_width;
	new->win_height = win_height;
	new->frame = (t_frame *)malloc(sizeof(t_frame));
	new->frame->img_ptr = mlx_new_image(new->mlx_ptr, win_width, win_height);
	new->frame->bpp = (int *)malloc(sizeof(int));
	new->frame->sizeline = (int *)malloc(sizeof(int));
	new->frame->endian = (int *)malloc(sizeof(int));
	new->frame->buffer = (int *)mlx_get_data_addr(new->frame->img_ptr,
					new->frame->bpp, new->frame->sizeline, new->frame->endian);
	new->fractal = NULL;
	new->thr = (t_threads *)malloc(sizeof(t_threads));
	new->thr->core1 = (pthread_t *)malloc(sizeof(pthread_t));
	new->thr->core2 = (pthread_t *)malloc(sizeof(pthread_t));
	new->thr->core3 = (pthread_t *)malloc(sizeof(pthread_t));
	new->thr->core4 = (pthread_t *)malloc(sizeof(pthread_t));
	return (new);
}
