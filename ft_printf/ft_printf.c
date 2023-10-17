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
		return (ft_putchar_fd(format, 1));
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

// int main(void)
// {
// 	char *ptr;
// 	char c;
// 	int count;

// 	c = 'x';
// 	ptr = &c;

// 	count = ft_printf("Character: %c\n", 'x');
// 	ft_printf("Integer: %i\n", 123456);
// 	ft_printf("Decimal: %d\n", 167);
// 	ft_printf("Unsigned int: %u\n", -345);
// 	ft_printf("String: %s\n", "hello");
// 	ft_printf("Hexadecimal: %x\n", 5986);
// 	ft_printf("HEXADECIMAL: %X\n", -6876);
// 	ft_printf("Pointer: %p\n", ptr);
// 	printf("Expected Pointer: %p\n", ptr);
// 	ft_printf("Return value: %d\n", count);
// 	ft_printf("Expected return value: %d\n", printf("Character: %c\n", 'x'));
// 	ft_printf("Return value: %d\n", ft_printf("hello %w world\n", 5));
// 	return (0);
// }