/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:44:42 by rmc-coma          #+#    #+#             */
/*   Updated: 2015/12/07 17:19:21 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strwrdcnt(const char *str, char c)
{
	size_t	wrdcnt;

	wrdcnt = 0;
	while (*str)
	{
		if (*str == c)
		{
			while (*str == c && *str)
				str++;
		}
		else
		{
			wrdcnt++;
			while (*str != c && *str)
				str++;
		}
	}
	return (wrdcnt);
}

static size_t	ft_strwrdlen(const char *str, char c)
{
	size_t	strwrdlen;

	strwrdlen = 0;
	while (*str && *str++ != c)
		strwrdlen++;
	return (strwrdlen);
}

static char		*ft_strgetwrd(const char *s, int index, char c)
{
	char	*str;
	char	*strrdr;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (index-- <= 0)
			break ;
		while (*s != c && *s)
			s++;
	}
	str = (char *)malloc(sizeof(char) * (ft_strwrdlen(s, c) + 1));
	if (str == NULL)
		return (NULL);
	strrdr = str;
	while (*s && *s != c)
		*strrdr++ = *s++;
	*strrdr = 0;
	return (str);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**splitstr;
	size_t	swrdcnt;

	if (s == NULL || c == '\0')
		return (NULL);
	swrdcnt = ft_strwrdcnt((char *)s, c);
	splitstr = (char **)malloc(sizeof(char *) * (swrdcnt + 1));
	if (splitstr == NULL)
		return (NULL);
	splitstr[swrdcnt] = NULL;
	while (swrdcnt--)
	{
		splitstr[swrdcnt] = ft_strgetwrd((char *)s, (int)swrdcnt, c);
		if (splitstr[swrdcnt] == NULL)
			return (NULL);
	}
	return (splitstr);
}
