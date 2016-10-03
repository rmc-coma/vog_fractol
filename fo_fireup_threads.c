/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fo_fireup_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 03:21:59 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/03/22 05:21:57 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fo_fireup_threads(t_fo *obj, void *(*f)(void *))
{
	obj->thr->running = 0;
	obj->thr->lock = TRUE;
	pthread_create(obj->thr->core1, NULL, f, obj);
	while (obj->thr->lock == TRUE)
		continue ;
	obj->thr->running = 1;
	obj->thr->lock = TRUE;
	pthread_create(obj->thr->core2, NULL, f, obj);
	while (obj->thr->lock == TRUE)
		continue ;
	obj->thr->running = 2;
	obj->thr->lock = TRUE;
	pthread_create(obj->thr->core3, NULL, f, obj);
	while (obj->thr->lock == TRUE)
		continue ;
	obj->thr->running = 3;
	obj->thr->lock = TRUE;
	pthread_create(obj->thr->core4, NULL, f, obj);
	pthread_join(*(obj->thr->core1), NULL);
	pthread_join(*(obj->thr->core2), NULL);
	pthread_join(*(obj->thr->core3), NULL);
	pthread_join(*(obj->thr->core4), NULL);
}
