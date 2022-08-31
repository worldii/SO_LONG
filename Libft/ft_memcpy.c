/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:28:21 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 15:20:01 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	size_t	idx;

	idx = 0;
	if (dest == 0 && source == 0 && num > 0)
		return (dest);
	while (idx < num)
	{
		((unsigned char *) dest)[idx] = ((unsigned char *) source)[idx];
		idx++;
	}
	return (dest);
}
