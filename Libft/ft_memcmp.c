/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 06:21:22 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:23:06 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*pptr1;
	unsigned char	*pptr2;
	size_t			idx;

	idx = 0;
	pptr1 = (unsigned char *) ptr1 ;
	pptr2 = (unsigned char *) ptr2 ;
	while (idx < num)
	{
		if (*(pptr1 + idx) != *(pptr2 + idx))
			return (*(pptr1 + idx) - *(pptr2 + idx));
		idx++;
	}
	return (0);
}
