/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:08:15 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/02 18:58:49 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(char *dst, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		if (!dst[i++])
			return (--i);
	return (size);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n;
	size_t	i;
	size_t	res;

	i = 0;
	if (size <= (ft_strnlen(dst, size) + 1))
		return (ft_strnlen(dst, size) + ft_strlen(src));
	n = ft_strlen(dst);
	res = n + ft_strlen(src);
	while (src[i] != 0)
	{
		if (n < (size - 1))
			dst[n++] = src[i];
		i++;
	}
	dst[n] = 0;
	return (res);
}
