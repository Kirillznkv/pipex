/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 02:02:19 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/27 02:30:45 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int start_commands(t_commands *commands, char **env)
{
    close(1);
    close(0);
    dup2(commands->fd_in, 0);
    dup2(commands->fd_out, 1);
    execve(commands->cmd1[0], commands->cmd1, env);
    execve(commands->cmd2[0], commands->cmd2, env);
    return (0);
}
