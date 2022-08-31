/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:52:41 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:52:49 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	idx;
	int		slen;
	int		llen;

	slen = ft_strlen((char *)s);
	llen = len;
	if ((unsigned int) slen < start)
		llen = 0;
	else if (len > slen - start)
		llen = slen - start;
	sub = (char *) malloc(sizeof(char) * (llen + 1));
	if (sub == NULL)
		return (NULL);
	idx = 0;
	while (idx < len && (int) start + (int) idx < slen)
	{
		sub[idx] = s[start + idx];
		idx++;
	}
	sub[idx] = '\0';
	return (sub);
}
