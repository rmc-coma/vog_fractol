/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 08:41:43 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/02 16:57:40 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 && *s2 && n--)
	{
		if (*s1++ == *s2++)
			;
		else
			return (0);
	}
	if ((!*s1 && *s2) || (*s1 && !*s2))
		return (0);
	return (1);
}
