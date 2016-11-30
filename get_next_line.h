/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmadad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 10:01:45 by hmadad            #+#    #+#             */
/*   Updated: 2016/11/30 16:57:03 by hmadad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"

//typedef struct		s_file
//{
//	int		fd;
//	int		offset;
//}					t_file;

//typedef struct		s_list
//{
//	struct s_file	*content;
//	struct s_list	*next;
//}					t_list;

int		get_next_line(const int fd, char **line);

#endif
