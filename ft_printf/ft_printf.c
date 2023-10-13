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

int	ft_putptr(unsigned long int num)
{
	if (num == 0)
	{
		write(1, "(nil)", 1);
		return (5);
	}
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	return (ft_puthexa(num)+ 2);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	int		num;
	char	*str;
	unsigned long	n;
	va_list	ptr;

	i = 0;
	count = 0;
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			if (format[i + 1] == 'i' || format[i + 1] == 'd')
				count += ft_process_int(va_arg(ptr, int));
			else if (format[i + 1] == 'u')
				count += ft_process_unsigned_int(va_arg(ptr, unsigned));
			else if (format[i + 1] == 'c')
				count += ft_putchar_fd(va_arg(ptr, int), 1);
			else if (format[i + 1] == 's')
			{
				str = va_arg(ptr, char *);
				if (str == NULL)
				{
					ft_putstr_fd("(null)", 1);
					count += 6;				
				}
				else
					count += ft_putstr_fd(str, 1);
			}
			else if (format[i + 1] == 'x')
				count += ft_puthexa(va_arg(ptr, unsigned int));

			else if (format[i + 1] == 'X')
				count += ft_puthexa_upcase(va_arg(ptr, unsigned int));

			else if (format[i + 1] == 'p')
			{
				n = va_arg(ptr, unsigned long int);
				if (n == 0)
				{
					ft_putstr_fd("(nil)", 1);
					count += 5;
				}
				else
					count += ft_putptr(n);
			}
			else
				return (0);
			i += 2;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			write(1, "%", 1);
			count += 1;
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(ptr);
	return (count);
}

// int	main(void)
//  {
//  	char *ptr;
//  	char c = 'x';
//  	ptr = &c;
//  	int count;

// // 	// count = ft_printf("Character: %c\n", 'x');
// 	// count = ft_printf("%i", 123456);
// 	ft_printf("%d", ft_printf("Integer: %d\n", 167));
// //  // 	ft_printf("Unsigned int: %u\n", -345);
// //  // 	ft_printf("String: %s\n", "hello");
// //  // 	ft_printf("Hexadecimal: %x\n", -6);
// //  // 	printf("Expected Hexadecimal: %x\n", -6);
// //  // 	ft_printf("HEXADECIMAL: %X\n", -6876);
// //  // 	printf("Expected HEXADECIMAL: %X\n", -6876);
// //  // 	ft_printf("Pointer: %p\n", ptr);
// //  // 	printf("Expected Pointer: %p\n", ptr);
// //  // 	ft_printf("Test: %w hello\n", 5 );
// //  // 	ft_printf("Test number of args; %d, %d\n", 1, 2, 3);
// //  // 	ft_printf("Test %% at the end: %");
// //  // 	ft_printf(" %c ", 'x');

// //  	// count = ft_printf("This is a %s, num %d, %c hello %p f %x %u gg %d", "test", 145, 'x', ptr, 2578956, -125468, -125);
// // 	// printf("\nNum:%d\n", ft_printf("%u", -1525));
// // 	// printf("\nExpected num: %d\n", printf("%u", -1525));
// // 	// ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
// // 	// ft_printf(" NULL %s NULL ", NULL);
// // 	ft_printf("%s %s %s %s", "s1", "s2", "s3", "s4");
// // printf(" %p %p \n", ptr, ptr);
// // ft_printf(" %p %p \n", ptr, ptr);
// //  	return 0;
// }
