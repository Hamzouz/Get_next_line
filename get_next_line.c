/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:59:31 by hmadad            #+#    #+#             */
/*   Updated: 2016/12/06 14:07:35 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		check_buf(char* buf, char **all, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(*all, '\n')))
	{
		*line = ft_strsub(*all, 0, tmp - *all);
		*all = ft_strdup(tmp + 1);
		return (1);
	}
	if (ft_strcmp(buf, "") == 0)
	{
		*line = ft_strdup(*all);
		ft_strdel(&(*all));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*all = NULL;
	int			nb;

	if (read(fd, &buf, 0) >= 0)
	{
		while ((nb = read(fd, &buf, BUFF_SIZE)) > 0)
		{
			buf[nb] = '\0';
			((!all) ? (all = ft_strdup(buf)) : (all = ft_free_join(all, buf, 'L')));
			if (check_buf(buf, &all, line) == 1)
				return (1);
			ft_bzero(buf, BUFF_SIZE);
		}
		while (all && ft_strcmp(all, "") != 0)
			if (check_buf(buf, &all, line) == 1)
				return (1);
			return (0);
	}
	return (-1);
}
