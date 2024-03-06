/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:36:18 by oszwalbe          #+#    #+#             */
/*   Updated: 2024/02/11 18:36:21 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	invalid_arguments(void)
{
	ft_putendl_fd("./pipex infile cmd cmd outfile", 2);
	exit(EXIT_FAILURE);
}

void	invalid_arguments2(void)
{
	ft_putendl_fd("./pipex here_doc LIMITER cmd cmd outfile", 2);
	exit(EXIT_FAILURE);
}

void	escape(char *path)
{
	free(path);
	error_mess();
}

void	escape2(char *path, char **cmd)
{
	free(path);
	free_paths(cmd);
	error_cmd();
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
