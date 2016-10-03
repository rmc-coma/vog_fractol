/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:01:07 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/11/28 15:49:36 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*s1rdr;
	char	*s2rdr;
	int		s2len;

	s1rdr = (char *)s1;
	s2rdr = (char *)s2;
	s2len = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*s1rdr)
	{
		if (*s1rdr++ == *s2rdr++)
		{
			if (!*s2rdr)
				return (s1rdr - s2len);
		}
		else
		{
			s1rdr = (char *)s1++;
			s2rdr = (char *)s2;
		}
	}
	return (NULL);
}
