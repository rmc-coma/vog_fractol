/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:14:35 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/04 19:06:26 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmpstr;

	tmpstr = malloc(sizeof(char) * len);
	ft_memcpy(tmpstr, src, len);
	ft_memcpy(dst, tmpstr, len);
	free(tmpstr);
	return (dst);
}
