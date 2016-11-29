/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 09:59:31 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/29 17:18:59 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_errors(int n)
{
	if (n == -1)
		ft_putstr("le Dossier ne peux pas etre lu");
	return ;
}

int		check_buf(char *buf, char **line, char *all)
{
	char		*tmp;
	int			i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			ft_putstr("ICII\n");
			tmp = ft_strsub(buf, 0, (i + 1));
			ft_putstr(ft_strjoin(all, tmp));
			all = ft_strjoin(all, tmp);
			line = &all;
			ft_putstr("Je suis la\n");
			ft_putstr(all);
			return (1);
		}
		i++;
	}
	if (buf[i] == '\0')
		all = ft_free_join(all, buf, 'L');
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE];
	static char	*all = NULL;

	all = ft_memalloc(1);
	if (read(fd, &buf, 0) >= 0)
	{
		while (read(fd, &buf, BUFF_SIZE - 1) != 0)
		{
			buf[BUFF_SIZE - 1] = '\0';
			if (check_buf(buf, line, all) == 1)
				return(1);
		}
	}
	else
		ft_errors(-1);
	return (0);
}
