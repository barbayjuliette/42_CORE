/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:18:14 by jbarbay           #+#    #+#             */
/*   Updated: 2023/09/12 15:18:22 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		num = -num;
		ft_putchar_fd('-', fd);
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
	else
	{
		c = '0' + num;
		ft_putchar_fd(c, fd);
	}
}

static int	count_args(const char *format)
{
	int	i;
	int	count;

	i = 0;
	count = 0;

	while (format[i + 1])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			count++;
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	return (count);
}

static int	put_arg(char c)
{
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
		return (1);
	else if (c == 'c')
		return (2);
	else if (c == 's')
		return (3);
	else if (c == 'p')
		return (4);
	else if (c == 'u')
		return (5);
	else
		return (0);
}

int ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	int		type;
	va_list	ptr;

	count = count_args(format);
	i = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			type = put_arg(format[i + 1]);
			if (type == 0)
				return (1); // Error finish program
			else if (type == 1) // This is an int
			{
				ft_putnbr_fd(va_arg(ptr, int), 1);
			}
			else
				return (0);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;			
		}
	}
	va_end(ptr);
	return (0);
}

int main(void)
{	
	ft_printf("This is %d test %d %% tt %d", 1, 2, 3 );
	return 0;
}