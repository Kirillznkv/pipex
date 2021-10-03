#include "../includes/pipex.h"

static int fill_fd_pipe(t_commands *commands)
{
	int	i;

	i = -1;
	while (++i < commands->numders_cmd - 1)
		if (pipe((commands->fd)[i]))
			return (1);
	return (0);
}

static int dup_fd(int **fd, int i, int n)
{
	if (i && i < n - 1)
	{
		if (dup2(fd[i - 1][0], 0) == -1)
			return (1);
		if (dup2(fd[i][1], 1) == -1)
			return (1);
	}
	else if (i == 0)
	{
		if (dup2(fd[i][1], 1) == -1)
			return (1);
	}
	else
	{
		if (dup2(fd[i - 1][0], 0) == -1)
			return (1);
	}
	return (0);
}

int	start_commands(t_commands *commands, char **env)
{
	int	i;

	if (fill_fd_pipe(commands))
		return (error("Error: pipe\n"));
	i = -1;
	while (++i < commands->numders_cmd)
	{
		(commands->pid)[i] = fork();
		if ((commands->pid)[i] != 0)
		{
			close((commands->fd)[i][1]);
			(commands->fd)[i][1] = -1;
		}
		else
		{
			if (dup_fd(commands->fd, i, commands->numders_cmd - 1))//
				return (error("Error: dup"));
			if (exec_cmd())//
				return (error("error: exec"));
		}
	}
	return (0);
}