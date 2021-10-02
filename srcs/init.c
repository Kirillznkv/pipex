/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:08:34 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/03 00:54:14 by kshanti          ###   ########.fr       */
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

int set_commands(t_commands *commands, char **argv, int argc)
{
	int		i;
    char    *infile;
    char    *outfile;

    infile = ft_strdup(argv[0]);
	i = 0;
	while (++i < argc - 2)
		((commands->cmd)[i]).argv = get_command(argv[i]);
    outfile = ft_strdup(argv[i]);
	commands->fd_in = open(infile, O_RDONLY, 0644);
	commands->fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile)
    	free(infile);
	if (outfile)
    	free(outfile);
	while (--i > 0)
		if (((commands->cmd)[i]).argv == NULL)
			return (1);
	if (commands->fd_in == -1 || commands->fd_out == -1)
		return (1);
    return (0);
}
