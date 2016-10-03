/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmc-coma <rmc-coma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 02:18:18 by rmc-coma          #+#    #+#             */
/*   Updated: 2016/01/21 01:14:54 by rmc-coma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_seek_line(char **line, char *buff_save)
{
	char	*eol;

	eol = ft_strchr(buff_save, '\n');
	if (eol != NULL)
	{
		*eol = 0;
		*line = ft_strdup(buff_save);
		ft_memmove(buff_save, &eol[1], ft_strlen(&eol[1]) + 1);
		return (1);
	}
	if (0 < ft_strlen(buff_save))
	{
		*line = ft_strdup(buff_save);
		*buff_save = '\0';
		return (1);
	}
	return (0);
}

int	get_next_line(int const fd, char **line)
{
	static char	*buff_save = NULL;
	char		buffer[BUFF_SIZE + 1];
	char		*line_tmp;
	int			ret;

	if (line == NULL || 0 > fd || BUFF_SIZE <= 0)
		return (-1);
	if (buff_save == NULL)
		buff_save = ft_strnew(0);
	while (!ft_strchr(buff_save, '\n'))
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (-1 == ret)
			return (-1);
		if (0 == ret)
			break ;
		buffer[ret] = '\0';
		line_tmp = ft_strjoin(buff_save, buffer);
		free(buff_save);
		buff_save = line_tmp;
	}
	return (gnl_seek_line(line, buff_save));
}
