/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:02:19 by kshanti           #+#    #+#             */
/*   Updated: 2021/08/02 11:25:04 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//
void	output(char **a)
{
	int	i;

	i = -1;
	while (a && a[++i])
		printf("%d: %s\n", i, a[i]);
}
//

int start_commands(t_commands *commands, char **env)
{
	pid_t	pd1;
	pid_t	pd2;
	int		fd[2];

	pipe(fd);
	if (!find_exec(commands->cmd1, env))
		return (error("Error: exec not found\n") && struct_free(commands, NULL, NULL));
	if (!find_exec(commands->cmd2, env))
		return (error("Error: exec not found\n") && struct_free(commands, NULL, NULL));

    dup2(commands->fd_in, 0);
	dup2(fd[1], 1);
	pd1 = fork();
	if (!pd1)
	{
    	execve((commands->cmd1)[0], commands->cmd1, env);
		exit(1);//
	}
	waitpid(pd1, NULL, 0);

    dup2(fd[0], 0);
    dup2(commands->fd_out, 1);
	pd2 = fork();
	if (!pd2)
	{
    	execve((commands->cmd2)[0], commands->cmd2, env);
		exit(1);//
	}
	waitpid(pd2, NULL, 0);

    return (0);
}
