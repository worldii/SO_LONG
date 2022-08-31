/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 05:22:50 by jonghapa          #+#    #+#             */
/*   Updated: 2021/12/03 16:28:01 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || \
			c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	sum;

	sign = 1;
	sum = 0;
	while (ft_isspace(*str))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if (sign == 1 && ((sum == 922337203685477580 && *str - '0' > 7) \
					|| sum > 922337203685477580) && sum < 1000000000000000000)
			return (-1);
		else if (sign == -1 && ((sum == 922337203685477580 && *str - '0' > 8) \
					|| sum > 922337203685477580) && sum < 1000000000000000000)
			return (0);
		sum = sum * 10 + (*str - '0');
		str++;
	}
	return (sum * sign);
}
