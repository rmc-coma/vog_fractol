/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:49:42 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/02 18:59:10 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (i < n)
	{
		if ((((unsigned char *)dst)[i] = ((unsigned char *)src)[i])
			== (unsigned char)c)
			break ;
		i++;
	}
	if (((unsigned char *)src)[i] == (unsigned char)c)
		return (&dst[i + 1]);
	return (NULL);
}
