/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:57:42 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/10 18:05:12 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nextone;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		nextone = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextone;
	}
}
