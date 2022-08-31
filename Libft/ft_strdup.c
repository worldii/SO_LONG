/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 06:07:04 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:33:31 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*temp;
	int		len;
	int		sidx;
	int		tidx;

	sidx = 0;
	tidx = 0;
	len = ft_strlen(src);
	temp = (char *) malloc (sizeof(char) * len + 1);
	if (temp == NULL)
		return (NULL);
	while (src[sidx])
	{
		temp[tidx++] = src[sidx++];
	}
	temp[tidx] = 0;
	return (temp);
}
