/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:11:34 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/30 17:17:43 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		ft_putstr(line);
	return (0);
}
