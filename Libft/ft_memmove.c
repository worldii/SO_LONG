/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:51:17 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 15:21:29 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t	idx;

	if (dest == NULL && src == NULL && num > 0)
		return (dest);
	if (src < dest)
	{
		idx = num ;
		while (idx-- > 0)
			((unsigned char *)dest)[idx] = ((unsigned char *)src)[idx];
	}
	else
	{
		idx = -1;
		while (++idx < num)
			((unsigned char *)dest)[idx] = ((unsigned char *)src)[idx];
	}
	return (dest);
}
