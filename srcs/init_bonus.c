/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 01:08:34 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/05 09:45:52 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	get_number_arg(char *arg)
{
	int	res;
	int	i;

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

static int	get_number_simbols(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && arg[i] != ' ')
		i++;
	return (i);
}

static char	**get_command(char *arg)
{
	char	**res;
	int		inx;
	int		i;
	int		n;

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

static char	*getInFile(char **argv, int *i, int *n)
{
	int		fd;
	int		len;
	char	*line;

	if (!isEquals(argv[*i], "here_doc"))
		return (ft_strdup(argv[*i]));
	--(*n);
	fd = open("./.shell_file", O_RDWR | O_CREAT | O_TRUNC, 0777);
	len = ft_strlen(argv[++(*i)]);
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strlen(line) != len || ft_strncmp(line, argv[*i], len))
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		else
		{
			free(line);
			break ;
		}
	}
	close(fd);
	return (ft_strdup("./.shell_file"));
}

int	set_commands(t_commands *commands, char **argv)
{
	int		i;
	int		j;
	char	*infile;
	char	*outfile;

	i = 1;
	infile = getInFile(argv, &i, &(commands->numders_cmd));
	j = -1;
	while (++j < commands->numders_cmd)
		((commands->cmd)[j]).argv = get_command(argv[++i]);
	outfile = ft_strdup(argv[++i]);
	commands->fd_in = open(infile, O_RDONLY, 0644);
	commands->fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile)
		free(infile);
	if (outfile)
		free(outfile);
	while (--j > 0)
		if (((commands->cmd)[i]).argv == NULL)
			return (error("Error: malloc\n"));
	if (commands->fd_in == -1 || commands->fd_out == -1)
		return (error("Error: fd in/out\n"));
	return (0);
}
