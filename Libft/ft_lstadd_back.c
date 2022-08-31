/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:10:46 by jonghapa          #+#    #+#             */
/*   Updated: 2021/11/28 02:21:34 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (*lst)
	{
		cur = *lst;
		while (cur -> next)
			cur = cur -> next;
		cur -> next = new;
	}
	else
	{
		*lst = new;
	}
}
