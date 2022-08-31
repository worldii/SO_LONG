/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:38:31 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:53:59 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	idx;
	char			*temp;
	int				ssize;

	ssize = ft_strlen((char *) s);
	temp = (char *) malloc(sizeof(char) * (ssize + 1));
	if (temp == NULL)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		temp[idx] = f(idx, s[idx]);
		idx++;
	}
	temp[idx] = '\0';
	return (temp);
}
