/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:01:00 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/07 17:21:47 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*s && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	while (s[i])
		i++;
	if (i <= 0)
		return ("");
	while (s[--i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		;
	str = (char *)malloc(sizeof(char) * (++i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = 0;
	while (i--)
		str[i] = s[i];
	return (str);
}
