/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:34:49 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:59:50 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cur;
	t_list	*templist;

	templist = NULL;
	cur = lst;
	while (cur)
	{
		new = ft_lstnew(f(cur->content));
		if (new == NULL)
		{
			ft_lstclear(&templist, del);
			return (NULL);
		}	
		ft_lstadd_back(&templist, new);
		cur = cur -> next;
	}
	return (templist);
}
