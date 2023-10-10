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

void	ft_putptr(unsigned long num)
{
	if (num == 0)
		write(1, "(nil)", 1);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_puthexa(num);
}

int	ft_printf(const char *format, ...)
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
			// INTEGER
			if (format[i + 1] == 'i' || format[i + 1] == 'd')
				ft_putnbr_fd(va_arg(ptr, int), 1);
			// UNSIGNED INT
			else if (format[i + 1] == 'u')
				ft_put_unsigned_fd(va_arg(ptr, unsigned int), 1);
			// CHARACTER
			else if (format[i + 1] == 'c')
				ft_putchar_fd(va_arg(ptr, int), 1);
			// STRING
			else if (format[i + 1] == 's')
				ft_putstr_fd(va_arg(ptr, char*), 1);
			// HEXADECIMAL LOWERCASE
			else if (format[i + 1] == 'x')
				ft_puthexa(va_arg(ptr, unsigned int));
			// HEXADECIMAL UPPERCASE
			else if (format[i + 1] == 'X')
				ft_puthexa_upcase(va_arg(ptr, unsigned int));
			// POINTER
			else if (format[i + 1] == 'p')
				ft_putptr(va_arg(ptr, unsigned long));
			else
				return (0);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			i += 2;
		}
		// If % as last character
			// ADD CODE
		else
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	va_end(ptr);
	return (0);
}

 int	main(void)
 {
 	char *ptr;
 	char c = 'x';
 	ptr = &c;
	// ft_printf("Character: %c\n", 'x');
	// ft_printf("Integer: %i\n", 167);
	// ft_printf("Integer: %d\n", 167);
 // 	ft_printf("Unsigned int: %u\n", -345);
 // 	ft_printf("String: %s\n", "hello");
 // 	ft_printf("Hexadecimal: %x\n", -6);
 // 	printf("Expected Hexadecimal: %x\n", -6);
 // 	ft_printf("HEXADECIMAL: %X\n", -6876);
 // 	printf("Expected HEXADECIMAL: %X\n", -6876);
 		ft_printf("Pointer: %p\n", ptr);
 		printf("Expected Pointer: %p\n", ptr);
 // 	ft_printf("Test: %w hello\n", 5 );
 // 	ft_printf("Test number of args; %d, %d\n", 1, 2, 3);
 // 	ft_printf("Test %% at the end: %");
 // 	ft_printf(" %c ", 'x');
 	return 0;
}
