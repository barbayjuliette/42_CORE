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

#include "ft_printf.h"

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

int	check_letter_conversion(char format, va_list ptr)
{
	if (format == 'i' || format == 'd')
		return (ft_process_int(va_arg(ptr, int)));
	else if (format == 'u')
		return (ft_process_unsigned_int(va_arg(ptr, unsigned)));
	else if (format == 'c')
		return (ft_putchar_fd(va_arg(ptr, int), 1));
	else if (format == 's')
		return (ft_process_str(va_arg(ptr, char *)));
	else if (format == 'x')
		return (ft_puthexa(va_arg(ptr, unsigned int)));
	else if (format == 'X')
		return (ft_puthexa_upcase(va_arg(ptr, unsigned int)));
	else if (format == '%')
		return (ft_putchar_fd('%', 1));
	else if (format == 'p')
		return (ft_putptr(va_arg(ptr, unsigned long)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	ptr;

	i = 0;
	count = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += check_letter_conversion(format[i + 1], ptr);
			i += 2;
		}
		else
		{
			count += ft_putchar_fd(format[i], 1);
			i++;
		}
	}
	va_end(ptr);
	return (count);
}
