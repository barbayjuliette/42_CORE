/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:51 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/05 17:03:13 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_str(char *str, int *count)
{
	int	i;

	if (str == NULL)
		ft_putstr("(null)", count);
	else
	{
		i = 0;
		while (str[i])
		{
			*count += write(1, &str[i], 1);
			i++;
		}
	}
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

void	ft_putptr(unsigned int num, int *count)
{
	ft_putchar('0', count);
	ft_putchar('x', count);
	if (num == 0)
		ft_putchar('0', count);
	else
		put_nbr_base(num, 16, "0123456789abcdef", count);
}

void	put_nbr_base(long long int num, int len, char *base, int *count)
{
	if (num < 0)
	{
		ft_putchar('-', count);
		num = -num;
	}
	if (num >= len)
		put_nbr_base(num / len, len, base, count);
	ft_putchar(base[num % len], count);
}

void	ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}
