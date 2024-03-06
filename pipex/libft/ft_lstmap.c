/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oszwalbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:17:51 by oszwalbe          #+#    #+#             */
/*   Updated: 2023/11/10 18:50:34 by oszwalbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*newcontent;
	t_list	*newelm;
	t_list	*newlist;

	if (!lst || !f)
		return (NULL);
	newlist = 0;
	while (lst != NULL)
	{
		newcontent = f(lst->content);
		newelm = ft_lstnew(newcontent);
		if (newcontent == NULL)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newelm);
		lst = lst->next;
	}
	return (newlist);
}
