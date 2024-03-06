/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:14:24 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/09 22:00:42 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
/*
int	main(void) {
	const char *s1 = "Hello, ASCII value above 127: ç";
	const char *s2 = "Hello, ASCII value above 127: è";

	int result = ft_strncmp(s1, s2, '\0');

	if (result < 0) {
		printf("s1 is less than s2.\n");
	} else if (result > 0) {
		printf("s2 is less than s1.\n");
	} else {
		printf("s1 is equal to s2.\n");
	}

	return (0);
}*/
