/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:11:14 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/10 15:56:29 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	(dest[i] = '\0');
	return (dest);
}

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	taille;

	i = 0;
	taille = 0;
	while (dest[taille])
		taille++;
	while (src[i])
	{
		dest[taille + i] = src[i];
		i++;
	}
	dest[i + taille] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	ls;
	char	*p;
	char	*m;
	char	*n;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	m = (char *)s1;
	n = (char *)s2;
	ls = (ft_strlen(m) + (ft_strlen(n)));
	p = (char *)malloc((ls + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_strcpy(p, m);
	ft_strcat(p, n);
	return (p);
}
