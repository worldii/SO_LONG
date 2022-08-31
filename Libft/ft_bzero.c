/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:38:30 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 15:02:26 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *ptr, size_t n)
{
	size_t	idx;
	char	*temp;

	idx = 0;
	temp = (char *) ptr;
	while (idx < n)
	{
		*(temp + idx) = 0;
		idx++;
	}	
}
