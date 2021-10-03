/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:54:37 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/03 14:46:10 by kshanti          ###   ########.fr       */
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

int	free_struct(t_commands *commands)
{
	int i;

	if (commands->fd_in != -1)
		close(commands->fd_in);
	if (commands->fd_out != -1)
		close(commands->fd_out);
	if (commands->cmd)
	{
		i = -1;
		while (++i < commands->numders_cmd)
			free_mas(((commands->cmd)[i]).argv);
		free(commands->cmd);
	}
	free_masInt(commands->fd, commands->numders_cmd - 1);
	if (commands->pid)
		free(commands->pid);
	return (1);
}

int	free_masInt(int **arr, int n)
{
	int i;

	i = -1;
	while (arr && ++i < n)
		free(arr[i]);
	if (arr)
		free(arr);
	return (1);
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