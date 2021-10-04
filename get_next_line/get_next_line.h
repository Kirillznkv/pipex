/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:06:46 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/04 18:21:47 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "../includes/pipex.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

char		*ft_strchr(const char *s, int c);
int			maybe_line(char **static_buff, char **line);
int			get_next_line(int fd, char **line);
char		*func(char **buf);
int			func2(int *res, char **static_buff, char **line);

#endif
