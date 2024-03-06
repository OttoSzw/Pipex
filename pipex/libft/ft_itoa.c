/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:09:05 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/10 14:33:21 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*otto(int i, int count, char *str, long int num)
{
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
		i++;
	}
	str[count] = 0;
	while (count-- > i)
	{
		str[count] = (num % 10) + 48;
		num /= 10;
	}
	return (str);
}

static int	ft_count_num(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long int	num;

	num = n;
	count = ft_count_num(num);
	if (num < 0 || count == 0)
		count++;
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	return (otto(0, count, str, num));
}
