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

static char	*get_str_from_argv(char *str, char **argv)
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

static char	*get_path(char **env)
{
	char	*path_line;

	path_line = get_str_from_argv("PATH=", env);
	return (&(path_line[5]));
}

static int		is_finish_path(char *command, char **res)
{
	if (!ft_strncmp("./", command, 2) \
		|| !ft_strncmp("../", command, 3) \
		|| !ft_strncmp("/", command, 1))
	{
		if (!(access(command, X_OK)))
			*res = ft_strdup(command);
		return (1);
	}
	return (0);
}

static char	*check_matrix_path(char *path, char *name)
{
	char	*res;
	char	*save_to_free;

	res = ft_strjoin(path, "/");
	save_to_free = res;
	res = ft_strjoin(res, name);
	free(save_to_free);
	if (access(res, X_OK))
	{
		free(res);
		res = NULL;
	}
	return (res);
}

char	*find_exec(char **str, char **env)
{
	int		i;
	char	*res;
	char	*path;
	char	**path_matrix;
	char	**save_to_free;

	res = NULL;
	if (is_finish_path(*str, &res))
	{
		free(*str);
		*str = res;
		return (res);
	}
	path = get_path(env);
	path_matrix = ft_split(path, ':');
	save_to_free = path_matrix;
	i = -1;
	while (path_matrix[++i])
	{
		res = check_matrix_path(path_matrix[i], *str);
		if (res)
		{
			free_mas(save_to_free);
			free(*str);
			*str = res;
			return (res);
		}
	}
	free_mas(save_to_free);
	return (res);
}