/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:56:19 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/02 14:10:21 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (s == NULL)
		return (NULL);
	while (n--)
		if (*(unsigned char *)s++ == (unsigned char)c)
			return ((void *)--s);
	return (NULL);
}
