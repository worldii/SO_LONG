/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:56:11 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:48:50 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long long n)
{
	int	size;

	size = 0;
	if (n == 0)
	{
		size = 1;
		return (size);
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static void	ass_temp(long long temp, int size, char *str, int n)
{
	while (temp > 0)
	{
		str[--size] = temp % 10 + '0';
		temp = temp / 10;
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
}

char	*ft_itoa(int n)
{
	long long	temp;
	int			size;
	char		*str;

	temp = n;
	size = 0;
	if (n < 0)
	{
		temp = -temp;
		size++;
	}
	size += get_len(temp);
	str = (char *) malloc (sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	ass_temp(temp, size, str, n);
	return (str);
}
