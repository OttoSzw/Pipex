/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:35:44 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/02/07 15:35:46 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_cmd(void)
{
	ft_putendl_fd("Command not found", 2);
	exit(EXIT_FAILURE);
}

void	error_mess(void)
{
	char	*s;

	s = "Error";
	perror(s);
	exit(EXIT_FAILURE);
}

void	free_paths(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

char	*find_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*part_paths;
	int		i;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_paths = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_paths, cmd);
		free(part_paths);
		if (access(path, F_OK) == 0)
			return (free_paths(paths), path);
		free(path);
		i++;
	}
	return (free_paths(paths), NULL);
}

void	execute_command(char *av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (!cmd[0])
	{
		free_paths(cmd);
		error_cmd();
	}
	if (access(cmd[0], F_OK) == 0)
	{
		path = ft_strdup(cmd[0]);
		if (!path)
			escape(path);
	}
	else
	{
		path = find_path(cmd[0], env);
		if (!path)
			escape2(path, cmd);
	}
	if (execve(path, cmd, env) == -1)
		escape(path);
}

// void	execute_command(char *av, char **env)
// {
// 	char	**cmd;
// 	char	*path;

// 	cmd = ft_split(av, ' ');
// 	if (!cmd[0])
// 	{
// 		free_paths(cmd);
// 		error_cmd();
// 	}
// 	path = find_path(cmd[0], env);
// 	if (!path)
// 	{
// 		if (access(cmd[0], F_OK) == 0)
// 		{
// 			path = ft_strdup(cmd[0]);
// 			if (!path)
// 				escape(path);
// 		}

// 	}
// 		// escape2(path, cmd);
// 	// else
// 	// {
// 	// 	// path = ft_strdup(cmd[0]);
// 	// 	// if (!path)
// 	// 	// 	escape(path);
// 	// }
// 	if (execve(path, cmd, env) == -1)
// 		escape(path);
// }