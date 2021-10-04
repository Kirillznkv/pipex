/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshanti <kshanti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 00:48:09 by kshanti           #+#    #+#             */
/*   Updated: 2021/10/04 18:54:41 by kshanti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "stdlib.h"
# include "stdio.h"//
# include "unistd.h"
# include "fcntl.h"
# include <sys/wait.h>

int	get_next_line(int fd, char **line);

typedef struct s_cmd
{
	char		**argv;
}				t_cmd;
typedef struct  s_commands
{
	int			numders_cmd;
    int         fd_in;
    int         fd_out;
    t_cmd		*cmd;
	int			**fd;
	pid_t		*pid;
}               t_commands;
/*------------------------Utils-----------------------------------------------*/
int			error(char *str);
void	    skip_spases(char *str, int *i);
int			free_struct(t_commands *commands);
int			free_masInt(int **arr, int n);
int		    free_mas(char **argv);
/*------------------------Base_Utils------------------------------------------*/
int			ft_strlen(char *str);
char		*ft_strdup(char *s);
int			ft_strlcat(char *dst, char *src, int size);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_strncmp(const char *str1, const char *str2, size_t num);
char	    *ft_substr(char *s, unsigned int start, size_t len);
int			isEquals(char *str1, char *str2);
/*------------------------Init------------------------------------------------*/
int			set_commands(t_commands *commands, char **argv);
/*------------------------Commands--------------------------------------------*/
int			start_commands(t_commands *commands, char **env);
/*------------------------Split-----------------------------------------------*/
char		**ft_split(char const *s, char c);
/*------------------------Find_exec-------------------------------------------*/
char	    *find_exec(char **str, char **env);

#endif
