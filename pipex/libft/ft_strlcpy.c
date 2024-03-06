/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:07:48 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/10 19:40:17 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <bsd/string.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	j = 0;
	while (src[j])
		j++;
	return (j);
}
/*
int	main(void)
{
	char	a[] = "coucou";
	char	b[] = "yovffdhdddddddd";
	char	c[] = "dddddd";
	char	d[] = "codddddddff";

	__builtin_printf("%zu\n", strlcpy(a, b, 10));
	__builtin_printf("%zu\n", ft_strlcpy(a, b, 10));
	__builtin_printf("%zu\n", strlcpy(c, d, 10));
	__builtin_printf("%zu", ft_strlcpy(c, d, 10));
	return (0);
}*/
