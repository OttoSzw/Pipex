/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:41:22 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/07 10:17:50 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>

int	ft_toupper(int c)
{
	while (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int	main(void)
{
	int	c = 'a';

	__builtin_printf("%c", ft_toupper(c));
	return (0);
}*/
