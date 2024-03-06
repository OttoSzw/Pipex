/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:51:40 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/02/12 19:51:41 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_child(int ac, char **av, t_pipex *pipex, char **env)
{
	if (pipex->id == 0)
	{
		if (pipex->i == 2)
			child(av[pipex->i], av[pipex->i - 1], pipex->pipe_fd, env);
		if (pipex->i == ac - 2)
			child3(av[pipex->i], av[pipex->i + 1], pipex->pipe_fd, env);
		else
			child2(av[pipex->i], pipex->pipe_fd, env);
		dup2(pipex->pipe_fd[1], STDOUT_FILENO);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
	}
}

void	exec_child(int ac, char **av, t_pipex *pipex, char **env)
{
	while (pipex->i <= ac - 2)
	{
		if (pipe(pipex->pipe_fd) == -1)
			error_mess();
		pipex->id = fork();
		if (pipex->id == -1)
			error_mess();
		do_child(ac, av, pipex, env);
		dup2(pipex->pipe_fd[0], STDIN_FILENO);
		close(pipex->pipe_fd[0]);
		close(pipex->pipe_fd[1]);
		pipex->i++;
	}
	while (wait(NULL) != -1)
		continue ;
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)calloc(10000, 1);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[++i] = '\0';
	*line = buffer;
	return (r);
}

void	here_doc(char *limiter, int ac)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (ac < 6)
		invalid_arguments2();
	if (pipe(fd) == -1)
		error_mess();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strcmp(line, limiter) == 0)
				exit(EXIT_SUCCESS);
			ft_putendl_fd(line, fd[1]);
			free(line);
		}
		exit(1);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}
