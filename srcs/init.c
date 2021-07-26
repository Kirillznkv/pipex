/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:08:34 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/27 02:39:50 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int     col_argc(char **argv)
{
    int res;

    if (*argv == NULL)
        return (0);
    res = 1;
    while (argv[res] && argv[res][0] == '-')
        res++;
    return (res);
}

char    **get_command(char **argv, int *i)
{
    int     inx;
    int     argc;
    char    **res;

    argc = col_argc(argv);
    if (!argc)
        return (NULL);
    res = (char **)malloc(sizeof(char *) * (argc + 1));
    if (!res)
        return (NULL);
    res[argc] = NULL;
    inx = -1;
    while (++inx < argc)
    {
        res[inx] = ft_strdup(argv[*i]);
        (*i)++;
    }
    return (res);
}

int    set_commands(t_commands *commands, char **argv)
{
    int     i;
    char    *infile;
    char    *outfile;

    i = 0;
    infile = ft_strdup(argv[i++]);
    commands->cmd1 = get_command(argv, &i);
    commands->cmd2 = get_command(argv, &i);
    if (!(commands->cmd2))
        return (struct_free(commands, infile, NULL) && error("Error: argument\n"));
    if (argv[i])
        outfile = ft_strdup(argv[i++]);
    else
        return (struct_free(commands, infile, NULL) && error("Error: argument\n"));
    if (argv[i])
        return (struct_free(commands, infile, outfile) && error("Error: argument\n"));
    commands->fd_in = open(infile, O_RDONLY, 0644);
    if (commands->fd_in == -1)
        return (struct_free(commands, infile, outfile) && error("Error: infile\n"));
    commands->fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (commands->fd_in == -1)
        return (struct_free(commands, infile, outfile) && error("Error: outfile\n"));
    free(infile);
    free(outfile);
    return (0);
}
