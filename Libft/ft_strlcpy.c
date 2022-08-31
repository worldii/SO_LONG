/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:07:45 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 15:22:17 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;

	idx = 0;
	if (size > 0)
	{
		while (idx + 1 < size && src[idx])
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	while (src[idx])
		idx++;
	return (idx);
}
