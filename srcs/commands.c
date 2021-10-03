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
	if (i == 0)
	{
		close(fd[i][0]);
		if (dup2(fd[i][1], 1) == -1)
			return (1);
	}
	else if (i < n)
	{
		close(fd[i - 1][1]);
		close(fd[i][0]);
		if (dup2(fd[i - 1][0], 0) == -1)
			return (1);
		if (dup2(fd[i][1], 1) == -1)
			return (1);
	}
	else
	{
		close(fd[i - 1][1]);
		if (dup2(fd[i - 1][0], 0) == -1)
			return (1);
	}
	return (0);
}

static int exec_cmd(char **argv, char **env)
{
	if (!find_exec(argv, env))
		exit(error("Error: exec not found\n"));
	execve(argv[0], argv, env);
	exit(error("Error: exec error\n"));
	return (1);
}

static void waiting(t_commands *commands)
{
	int	i;
	int	status;
	int	error_code;

	i = commands->numders_cmd;
	while (--i)
	{
		waitpid((commands->pid)[i], &status, WUNTRACED | WCONTINUED);
		if (i > 0)
			close((commands->fd)[i - 1][0]);
		error_code = WEXITSTATUS(status);
		if (error_code)
			exit(error_code);
	}
}

int	start_commands(t_commands *commands, char **env)
{
	int	i;

	if (fill_fd_pipe(commands))
		return (error("Error: pipe\n"));
	// fcntl((commands->fd)[0][0], F_SETFL, O_NONBLOCK);
	i = -1;
	while (++i < commands->numders_cmd)
	{
		(commands->pid)[i] = fork();
		if ((commands->pid)[i] != 0)
		{
			if (i < commands->numders_cmd - 1)
				close((commands->fd)[i][1]);
		}
		else
		{
			if (dup_fd(commands->fd, i, commands->numders_cmd - 1))
				return (error("Error: dup"));
			if (exec_cmd((commands->cmd)[i].argv, env))
				return (1);
		}
	}
	waiting(commands);
	return (0);
}