/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:10:20 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:04:08 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	char	*temp;

	len = ft_strlen(str);
	temp = (char *) str + len;
	while (temp >= str)
	{
		if (*temp == (char) c)
			return (temp);
		temp--;
	}
	return (0);
}
