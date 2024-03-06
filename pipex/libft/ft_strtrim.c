/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:25:01 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/08 15:14:08 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

/*
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*r;
	size_t	i;

	i = 0;
	r = (char *)s;
	while (r[i])
	{
		if (r[i] == c)
			return(&r[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	if (start > ft_strlen(s))
		return (NULL);
	p = (char *)malloc((len + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (i < len && s[start + i] != '\0')
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return(p);
}
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		len;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[len - 1]) && len > 0)
		len--;
	dest = ft_substr(s1, 0, len);
	return (dest);
}
/*
int	main(void)
{
	char src[] = "cou/cou/cou";
	char dest[] = "cou";

	__builtin_printf("%s", ft_strtrim(src, dest));
	return (0);
}*/
