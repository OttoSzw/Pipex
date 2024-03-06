/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:41:17 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/10 14:34:00 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < n)
	{
		c1 = ((const unsigned char *)s1)[i];
		c2 = ((const unsigned char *)s2)[i];
		if (c1 != c2)
		{
			return (c1 - c2);
		}
		i++;
	}
	return (0);
}
