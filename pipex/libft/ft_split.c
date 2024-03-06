/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:15:10 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/10 19:11:46 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countword(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static int	ft_len(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*p;
	int		i[3];

	i[0] = 0;
	i[2] = 0;
	p = (char *)s;
	tab = (char **)ft_calloc(sizeof(char *), (countword(&p[i[0]], c) + 1));
	if (!s || !tab)
		return (0);
	while (i[2] < countword(p, c))
	{
		while (p[i[0]] == c)
			i[0]++;
		tab[i[2]] = (char *)ft_calloc(sizeof(char), ft_len(&p[i[0]], c) + 1);
		if (!tab[i[2]])
			return (0);
		i[1] = 0;
		while (p[i[0]] && p[i[0]] != c)
			tab[i[2]][i[1]++] = p[i[0]++];
		tab[i[2]][i[1]] = '\0';
		i[2]++;
	}
	return (tab[i[2]] = NULL, tab);
}
