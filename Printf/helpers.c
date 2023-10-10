/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:05:40 by jbarbay           #+#    #+#             */
/*   Updated: 2023/10/10 11:05:45 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_put_unsigned_fd(unsigned int n, int fd)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = '0' + n;
		ft_putchar_fd(c, fd);
	}
}

void	ft_puthexa(unsigned int n)
{
	if (n < 16)
		ft_putchar_fd("0123456789abcdef"[n], 1);
	else
	{
		ft_puthexa(n / 16);
		ft_putchar_fd("0123456789abcdef"[n % 16], 1);
	}
}

void	ft_puthexa_upcase(unsigned int n)
{
	if (n < 16)
		ft_putchar_fd("0123456789ABCDEF"[n], 1);
	else
	{
		ft_puthexa_upcase(n / 16);
		ft_putchar_fd("0123456789ABCDEF"[n % 16], 1);
	}
}