/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:51:28 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/03 01:12:58 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int m_struct(t_commands *commands, int argc)
{
	int	i;

	commands->numders_cmd = argc - 3;
	commands->cmd = (t_cmd*)malloc((commands->numders_cmd) * sizeof(t_cmd));
	commands->pid = (pid_t*)malloc((commands->numders_cmd) * sizeof(pid_t));
	commands->fd = (int**)malloc((commands->numders_cmd - 1)* sizeof(int*));
	if (commands->cmd == NULL || commands->pid == NULL || commands->fd == NULL)
		return (1);
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
    if (m_struct(&commands, argc) || set_commands(&commands, &(argv[1]), argc))
        return (1);//need free
    // if (start_commands(&commands, env))
    //     return (1);
    return (0);
}