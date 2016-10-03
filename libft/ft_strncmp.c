/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:24:22 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/02 12:20:35 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;
	size_t	i;

	c = 0;
	i = 0;
	while (i++ < n && *s1)
		c += *(unsigned char *)s1++;
	i = 0;
	while (i++ < n && *s2)
		c -= *(unsigned char *)s2++;
	return (c);
}
