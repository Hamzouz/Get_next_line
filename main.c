/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:11:34 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/29 16:21:01 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		i;
	char	**tab;
	int		fd;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, tab);
	i++;
	return (0);
}
