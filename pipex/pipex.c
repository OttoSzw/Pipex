/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:35:36 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/02/07 15:35:37 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		error_mess();
	dup2(fd, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_command(av[2], env);
}

void	child2(char **av, int *pipe_fd, char **env)
{
	int	fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_mess();
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	execute_command(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	pid_t	id;
	int		pipe_fd[2];

	if (ac != 5)
		invalid_arguments();
	if (access(av[1], F_OK) == -1)
		error_mess();
	if (pipe(pipe_fd) == -1)
		error_mess();
	id = fork();
	if (id == -1)
		error_mess();
	if (id == 0)
		child(av, pipe_fd, env);
	id = fork();
	if (id == 0)
		child2(av, pipe_fd, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(0, NULL, 0);
	waitpid(0, NULL, 0);
	return (0);
}
