/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:21:31 by kshanti           #+#    #+#             */
/*   Updated: 2021/08/02 11:47:17 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_str_from_argv(char *str, char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (!(ft_strncmp(argv[i], str, ft_strlen(str))))
			break ;
	}
	return (argv[i]);
}

char	*get_path(char **env)
{
	char	*path_line;

	path_line = get_str_from_argv("PATH=", env);
	return (&(path_line[5]));
}

int		is_finish_path(char *command, char **res)
{
	if (!ft_strncmp("./", str, 2) \
		|| !ft_strncmp("../", str, 3) \
		|| !ft_strncmp("/", str, 1))
	{
		*res = ft_strdup(command);
		return (1);
	}
	return (0);
}

char	*find_exec(char *str, char **env)
{
	char	*res;
	char	*path;
	char	**path_matrix;

	res = NULL;
	if (is_finish_path(str, &res))
		return (res);
	path = get_path(env);
	path_matrix = ft_split(path, ':');
	
}