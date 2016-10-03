/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:51:24 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/04 18:30:32 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_dgtcnt(int n)
{
	int				i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			sgn;
	int				i;
	unsigned int	ncpy;
	char			*str;

	sgn = n >= 0 ? 0 : 1;
	i = ft_dgtcnt(n);
	ncpy = sgn ? (unsigned int)-n : (unsigned int)n;
	str = (char *)malloc(sizeof(char) * (i + 1 + sgn));
	if (str == NULL)
		return (NULL);
	if (sgn)
	{
		str[0] = '-';
		i++;
	}
	str[i] = 0;
	if (!n)
		str[0] = '0';
	while (ncpy)
	{
		str[--i] = ncpy % 10 + 48;
		ncpy /= 10;
	}
	return (str);
}
