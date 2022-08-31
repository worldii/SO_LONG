/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:30:58 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 15:17:09 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void	*ptr, int value, size_t n)
{
	size_t			idx;
	unsigned char	*temp;

	temp = (unsigned char *) ptr;
	idx = 0;
	while (idx < n)
	{
		*(temp + idx) = (unsigned char) value;
		idx++;
	}
	return (ptr);
}
