/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:54:37 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/03 14:22:28 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int error(char *str)
{
    write(2, str, ft_strlen(str));
    return (1);
}

void	skip_spases(char *str, int *i)
{
	while (str && str[*i] == ' ')
		(*i)++;
}

int	free_mas(char **argv)
{
	int	i;

	i = -1;
	while (argv && argv[++i])
		free(argv[i]);
	if (argv)
		free(argv);
	return (1);
}