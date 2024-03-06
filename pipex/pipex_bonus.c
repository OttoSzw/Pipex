/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:51:33 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/02/12 19:51:35 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char *av, char *av2, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(av2, O_RDONLY, 0777);
	if (fd == -1)
		error_mess();
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_command(av, env);
}

void	child2(char *av, int *pipe_fd, char **env)
{
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_command(av, env);
}

void	child3(char *av, char *av2, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(av2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_mess();
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_command(av, env);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		invalid_arguments();
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		pipex.i = 3;
		here_doc(av[2], ac);
		exec_child(ac, av, &pipex, env);
	}
	else
	{
		pipex.i = 2;
		exec_child(ac, av, &pipex, env);
	}
	return (0);
}
