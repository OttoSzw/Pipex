/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:08:49 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/10 19:48:50 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	j;

	if ((!little || !big) && len == 0)
		return (0);
	i = 0;
	j = 0;
	b = (char *)big;
	l = (char *)little;
	if (l[j] == '\0')
		return (b);
	while (b[i] && i < len)
	{
		j = 0;
		while (b[i + j] == l[j] && (i + j) < len && l[j] != '\0')
		{
			j++;
			if (l[j] == '\0')
				return (&b[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	p[] = "coucou je m apelle otto";
	char	ch[] = "je";
	size_t	len = 15;

	__builtin_printf("%s", ft_strnstr(p, ch, len));
	return (0);
}*/
