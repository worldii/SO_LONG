/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:08:40 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:27:36 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	find_str(const char *big, const char *little, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len && *big && *little)
	{
		if (*big != *little)
			return (0);
		big++;
		little++;
		idx++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	idx;
	int		llen;

	idx = 0;
	llen = 0;
	if (big == NULL && len == 0)
		return (0);
	if (little[0] == 0)
		return ((char *) big);
	llen = ft_strlen(little);
	while (big[idx] != 0 && idx + llen <= len)
	{
		if (find_str(big + idx, little, len) == 1)
			return ((char *)(big + idx));
		idx++;
	}
	return (0);
}
