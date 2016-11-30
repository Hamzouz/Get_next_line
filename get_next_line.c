/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:59:31 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/30 17:14:50 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_errors(int n)
{
	if (n == -1)
		ft_putstr("le Dossier ne peux pas etre lu");
	return ;
}

int		check_buf(char *buf, char **line)
{
	char		*tmp;
	int			i;
	static char	*all = NULL;
	static char *reste = NULL;

	i = 0;
	if (reste)
	{
		all = reste;
		reste = NULL;
	}
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			if (!all)
				all = ft_strsub(buf, 0, i);
			else
			{
				reste = ft_strsub(buf, i, (ft_strlen(buf) - i));
				all = ft_strjoin(all, ft_strsub(buf, 0, i));
			}
			*line = all;
			return (1);
		}
		i++;
	}
	if (buf[i] == '\0')
	{
		if (!all)
			all = ft_strdup(buf);
		else
			all = ft_strjoin(all, buf);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE];

	if (read(fd, &buf, 0) >= 0)
	{
		while (read(fd, &buf, BUFF_SIZE - 1) != 0)
		{
			buf[BUFF_SIZE - 1] = '\0';
			if (check_buf(buf, line) == 1)
				return(1);
			ft_bzero(buf, ft_strlen(buf));
		}
		*line = buf;
	}
	else
		ft_errors(-1);
	return (0);
}
