/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:40:03 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/10 14:23:10 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb * size == 0)
	{
		result = malloc(0);
		if (!result)
			return (NULL);
		return (result);
	}
	else if (!nmemb || !size || (nmemb * size) / size != nmemb)
		return (NULL);
	result = (void *)malloc(nmemb * size);
	if (!result)
		return (NULL);
	ft_bzero(result, (nmemb * size));
	return (result);
}
