/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:59:31 by hmadad            #+#    #+#             */
/*   Updated: 2016/12/04 16:07:38 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	buf_all(char *buf, char **all)
{
	if (!(*all))
		*all = ft_strdup(buf);
	else
		*all = ft_free_join(*all, buf, 'L');
}

int		check_buf(char **line, char **all)
{
	int		i;

	i = 0;
	if (*all)
	{
		while ((*all)[i])
		{
			if ((*all)[i] == '\n')
			{
				*line = ft_strsub(*all, 0, i);
				*all = ft_strsub(*all, i + 1, ft_strlen(*all) - i);
				return (1);
			}
			i++;
		}
		*line = *all;
		*all = ft_strsub(*all, i + 1, ft_strlen(*all) - i);
	}
	return (1);
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
			buf_all(buf, &all);
			ft_bzero(buf, BUFF_SIZE);
		}
		while (ft_strcmp(all, "") != 0 && check_buf(line, &all) == 1)
			return (1);
		return (0);
	}
	return (-1);
}
