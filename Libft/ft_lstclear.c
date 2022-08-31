/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:27:36 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:59:26 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*temp;

	if (*lst)
	{
		cur = *lst;
		while (cur)
		{
			temp = cur -> next;
			del(cur->content);
			free(cur);
			cur = temp;
		}
	}
	*lst = NULL;
}
