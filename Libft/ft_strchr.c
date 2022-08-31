/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:00:51 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:18:47 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char*str, int c)
{
	char	*temp;

	temp = (char *) str;
	while (*temp)
	{
		if (*temp == (char )c)
			return (temp);
		temp++;
	}
	if (*temp == (char) c)
		return (temp);
	return (0);
}
