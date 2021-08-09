/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:08:34 by kshanti           #+#    #+#             */
/*   Updated: 2021/07/31 19:07:47 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static  int get_number_arg(char *arg)
{
    int res;
    int i;

    i = 0;
    res = 0;
    while (arg[i])
    {
        skip_spases(arg, &i);
        if (arg[i])
            res++;
        while (arg[i] && arg[i] != ' ')
            i++;
    }
    return (res);
}

static  int get_number_simbols(char *arg)
{
    int i;

    i = 0;
    while (arg[i] && arg[i] != ' ')
        i++;
    return (i);
}

char    **get_command(char *arg)
{
    char    **res;
    int     inx;
    int     i;
    int     n;

    n = get_number_arg(arg);
    res = (char **)malloc((n + 1) * sizeof(char *));
    if (!res)
        return (NULL);
    res[n] = NULL;
    i = -1;
    inx = 0;
    while (++i < n)
    {
        skip_spases(arg, &inx);
        res[i] = ft_substr(arg, inx, get_number_simbols(&(arg[inx])));
        inx += get_number_simbols(&(arg[inx]));
    }
    return (res);
}

int set_commands(t_commands *commands, char **argv)
{
    char    *infile;
    char    *outfile;

    infile = ft_strdup(argv[0]);
    commands->cmd1 = get_command(argv[1]);
    commands->cmd2 = get_command(argv[2]);
    outfile = ft_strdup(argv[3]);
    if (!(commands->cmd2) || !(commands->cmd1) || !infile || !outfile)
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
