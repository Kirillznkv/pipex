/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:54:37 by kshanti           #+#    #+#             */
/*   Updated: 2021/08/02 11:22:23 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int error(char *str)
{
    write(2, str, ft_strlen(str));
    return (1);
}

int struct_free(t_commands *commands, char *s1, char *s2)
{
	int		i;
	char	**a;

	if (s1)
		free(s1);
	if (s2)
		free(s2);
	a = commands->cmd1;
	i = -1;
	while (a[++i])
		free(a[i]);
	if (commands->cmd1)
		free(commands->cmd1);
	a = commands->cmd2;
	i = -1;
	while (a[++i])
		free(a[i]);
	if (commands->cmd2)
		free(commands->cmd2);
	return (1);
}
