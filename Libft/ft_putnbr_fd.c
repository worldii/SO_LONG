/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <bbc2788@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:16:32 by jonghapa          #+#    #+#             */
/*   Updated: 2021/11/26 15:19:58 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_char(char c, int nb)
{
	write(nb, &c, 1);
}

static void	calculate(int nb, int fd)
{
	if (nb == 0)
		return ;
	calculate(nb / 10, fd);
	put_char((nb % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n >= 0)
	{
		calculate(n / 10, fd);
		put_char((n % 10) + '0', fd);
	}
	else
	{
		put_char('-', fd);
		calculate((-n) / 10, fd);
		put_char((-n) % 10 + '0', fd);
	}
}
