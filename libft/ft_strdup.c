/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 13:18:47 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/11/29 10:53:30 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	s1len;

	s1len = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (s1len + 1));
	if (str == NULL)
		return (NULL);
	str[s1len] = 0;
	while (s1len--)
		str[s1len] = s1[s1len];
	return (str);
}
