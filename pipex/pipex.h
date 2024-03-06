/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:18:01 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/02/07 15:18:04 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct pipex
{
	int		i;
	int		pipe_fd[2];
	pid_t	id;
}			t_pipex;

void		invalid_arguments(void);

void		invalid_arguments2(void);

void		error_mess(void);

void		error_cmd(void);

void		execute_command(char *av, char **env);

char		*find_path(char *cmd, char **env);

void		escape(char *path);

void		escape2(char *path, char **cmd);

void		free_paths(char **split);

void		child(char *av, char *av2, int *pipe_fd, char **env);

void		child2(char *av, int *pipe_fd, char **env);

void		child3(char *av, char *av2, int *pipe_fd, char **env);

void		do_child(int ac, char **av, t_pipex *pipex, char **env);

void		exec_child(int ac, char **av, t_pipex *pipex, char **env);

void		here_doc(char *limiter, int ac);

int			ft_strcmp(char *s1, char *s2);

#endif
