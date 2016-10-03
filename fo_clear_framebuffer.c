/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_clear_framebuffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 01:15:48 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/19 01:18:22 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_clear_framebuffer(t_fo *obj)
{
	t_size	win_size;
	t_size	i;

	win_size = obj->win_width * obj->win_height;
	i = 0;
	while (i < win_size)
		obj->frame->buffer[i++] = 0;
}
