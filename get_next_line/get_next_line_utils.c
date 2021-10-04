/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:26:17 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/04 19:49:26 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

char	*func(char **buf)
{
	*buf = (char *)malloc(BUFFER_SIZE + 1);
	return (*buf);
}

int	func2(int *res, char **static_buff, char **line)
{
	*res = maybe_line(static_buff, line);
	return (*res);
}
