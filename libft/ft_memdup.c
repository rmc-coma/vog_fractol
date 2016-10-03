/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 18:46:25 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/04 18:57:26 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *mem, size_t size)
{
	unsigned char	*dup;

	if (mem == NULL || size == 0)
		return (NULL);
	dup = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (dup == NULL)
		return (NULL);
	while (size--)
		dup[size] = ((unsigned char *)mem)[size];
	return ((void *)dup);
}
