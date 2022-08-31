/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 05:53:55 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:32:47 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;
	size_t	idx;

	idx = 0;
	temp = malloc (count * size);
	if (temp == NULL)
		return (NULL);
	while (idx < count * size)
		*((char *) temp + idx++) = 0;
	return (temp);
}
