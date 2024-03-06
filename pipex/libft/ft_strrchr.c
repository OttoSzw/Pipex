/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:51:27 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/09 18:31:40 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	size_t	i;

	i = ft_strlen(s);
	r = (char *)s;
	if (c == '\0')
		return (&r[i]);
	while (i > 0)
	{
		if (r[i] == (char)c)
			return (&r[i]);
		i--;
	}
	if (r[i] == (char)c)
		return (r + i);
	if (c > 127)
		return (NULL);
	return (NULL);
}
/*
int	main(void) {
	char s[] = "tripouille";
	char s2[] = "ltripouiel";
	char s3[] = "";

	printf("Test 1: %s\n", (ft_strrchr(s, 't') == s) ? "Passed" : "Failed");
	printf("Test 2: %s\n", (ft_strrchr(s, 'l') == s + 8) ? "Passed" : "Failed");
	printf("Test 3: %s\n", (ft_strrchr(s2, 'l') == s2
			+ 9) ? "Passed" : "Failed");
	printf("Test 4: %s\n", (ft_strrchr(s, 'z') == NULL) ? "Passed" : "Failed");
	printf("Test 5: %s\n", (ft_strrchr(s, 0) == s
			+ ft_strlen(s)) ? "Passed" : "Failed");
	printf("Test 6: %s\n", (ft_strrchr(s, 't'
				+ 256) == s) ? "Passed" : "Failed");
	char *empty = (char *)calloc(1, 1);
	printf("Test 7: %s\n", (ft_strrchr(empty,
				'V') == NULL) ? "Passed" : "Failed");
	free(empty);
	printf("Test 8: %s\n", (ft_strrchr(s3, 0) == s3) ? "Passed" : "Failed");

	printf("\n");
	return (0);
}*/
