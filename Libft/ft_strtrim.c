/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42seoul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:20:59 by jonghapa          #+#    #+#             */
/*   Updated: 2022/03/20 00:30:28 by jonghapark       ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ischarset(char s, char const *set)
{
	int	sidx;

	sidx = 0;
	while (set[sidx])
		if (set[sidx++] == s)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1len;
	char	*trimmed;
	int		sidx;

	sidx = 0;
	if (set == NULL)
		return (ft_strdup(s1));
	s1len = ft_strlen((char *)s1);
	while (s1len >= 1 && s1[s1len - 1] && ft_ischarset(s1[s1len - 1], set) == 1)
		s1len--;
	while (s1[sidx] && ft_ischarset(s1[sidx], set) == 1)
		sidx++;
	if (sidx >= s1len)
		return (ft_strdup(""));
	trimmed = (char *)malloc(sizeof(char) * (s1len - sidx + 1));
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, s1 + sidx, s1len - sidx + 1);
	return (trimmed);
}
