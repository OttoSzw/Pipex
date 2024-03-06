/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:14:28 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/09 14:35:46 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (*s)
	{
		f(i, s);
		s++;
		i++;
	}
}

/*
#include <stdio.h>

void	myFunction(unsigned int index, char *c) {
	if (index % 2 == 1) {
		*c = 'X'; // Remplacer les caractères aux indices pairs par 'X'
	}
}

int	main(void) {
	char str[] = "Hello";
	ft_striteri(str, &myFunction);
	printf("Résultat : %s\n", str);
	return (0);
}*/
