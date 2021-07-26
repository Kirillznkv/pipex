/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:54:37 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/27 02:34:16 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int error(char *str)
{
    write(2, str, ft_strlen(str));
    return (1);
}

int struct_free(t_commands *commands, char *s1, char *s2)
{
    char    **a;

    if (s1)
        free(s1);
    if (s2)
        free(s2);
    a = commands->cmd1;
    while (*a)
    {
        free(a);
        a++;
    }
    if (commands->cmd1)
        free(commands->cmd1);
    a = commands->cmd2;
    while (*a)
    {
        free(a);
        a++;
    }
    if (commands->cmd2)
        free(commands->cmd2);
    return (1);
}
