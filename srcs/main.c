/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:51:28 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/04 17:32:29 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int m_struct(t_commands *commands, int argc)
{
	int	i;

	commands->fd_in = -1;
	commands->fd_out = -1;
	commands->numders_cmd = argc - 3;
	commands->cmd = (t_cmd*)malloc((commands->numders_cmd) * sizeof(t_cmd));
	commands->pid = (pid_t*)malloc((commands->numders_cmd) * sizeof(pid_t));
	commands->fd = (int**)malloc((commands->numders_cmd - 1)* sizeof(int*));
	if (commands->cmd == NULL || commands->pid == NULL || commands->fd == NULL)
		return (error("Error: malloc\n"));
	i = -1;
	while (++i < commands->numders_cmd - 1)
	{
		(commands->fd)[i] = (int*)malloc(2 * sizeof(int));
		if ((commands->fd)[i] == NULL)
			return (1);
	}
	return (0);
}

int main(int argc, char **argv, char **env)
{
    t_commands   commands;

    if (argc < 5)
        return (error("Error: argument\n"));
    if (m_struct(&commands, argc) || set_commands(&commands, argv, argc))
        return (free_struct(&commands));
    if (start_commands(&commands, env))
        return (free_struct(&commands));
    return (0);
}