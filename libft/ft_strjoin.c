/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:40:28 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/02 19:02:32 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	strlen;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	strlen = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (strlen + 1));
	if (str == NULL)
		return (NULL);
	str[strlen] = 0;
	i = 0;
	while ((str[i] = *s1++))
		i++;
	while ((str[i] = *s2++))
		i++;
	return (str);
}
