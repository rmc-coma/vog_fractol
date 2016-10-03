/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:01:07 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/02 16:28:20 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*s1rdr;
	char	*s2rdr;
	int		i;
	size_t	ncpy;

	s1rdr = (char *)s1;
	s2rdr = (char *)s2;
	if (!*s2)
		return ((char *)s1);
	i = 1;
	ncpy = n;
	while (*s1rdr && *s2rdr && n--)
		if (*s1rdr++ == *s2rdr++)
		{
			if (!*s2rdr)
				return (s1rdr - ft_strlen(s2));
		}
		else
		{
			n = ncpy - i;
			s1rdr = (char *)s1 + i++;
			s2rdr = (char *)s2;
		}
	return (0);
}
