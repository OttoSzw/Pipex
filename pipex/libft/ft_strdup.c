/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:45:36 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/09 15:28:50 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!(p))
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int	main(void)
{
	char	tab[] = "coucou";
	__builtin_printf("%s", ft_strdup(tab));
	return (0);
}*/
