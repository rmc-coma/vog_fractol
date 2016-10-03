/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:50:18 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/02 16:38:02 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mem;

	mem = (char *)malloc(sizeof(char) * size);
	if (mem == NULL)
		return (NULL);
	while (size--)
		mem[size] = 0;
	return ((void *)mem);
}
