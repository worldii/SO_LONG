/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:20:06 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:11:09 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				s1idx;
	int				s2idx;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *) s1;
	ss2 = (unsigned char *) s2;
	s1idx = 0;
	s2idx = 0;
	if (n == 0)
		return (0);
	while (ss1[s1idx] != '\0' && ss2[s2idx] != '\0' && n != 0)
	{	
		if (ss1[s1idx] != ss2[s2idx])
			return (ss1[s1idx] - ss2[s2idx]);
		n--;
		if (n == 0)
			return (0);
		s1idx++;
		s2idx++;
	}
	return (ss1[s1idx] - ss2[s2idx]);
}
