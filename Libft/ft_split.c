/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 00:43:22 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:46:54 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
			while (*s && *s == c)
				s++;
		}
	}
	return (count);
}

static char	**free_word(char **word, int widx)
{
	int	idx;

	idx = 0;
	while (idx < widx)
		free(word[idx++]);
	free(word);
	return (NULL);
}

static int	ass_word(char const *s, char c, char **word, int *widx)
{
	int	tempcount;

	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tempcount = 0;
			while (*s && *s != c)
			{
				tempcount++;
				s++;
			}
			s -= tempcount;
			word[*widx] = (char *) malloc(sizeof(char) * (tempcount + 1));
			tempcount = 0;
			if (word[*widx] == NULL)
				return (-1);
			while (*s && *s != c)
				word[*widx][tempcount++] = *s++;
			word[(*widx)++][tempcount] = '\0';
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**word;
	int		count;
	int		widx;

	widx = 0;
	count = count_word(s, c);
	word = (char **) malloc (sizeof(char *) * (count + 1));
	if (word == NULL)
		return (NULL);
	if (ass_word(s, c, word, &widx) == -1)
		return (free_word(word, widx));
	word[count] = NULL;
	return (word);
}
