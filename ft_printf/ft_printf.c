/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:18:14 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/05 17:01:18 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_letter_conversion(char format, va_list *ptr, int *count)
{
	if (format == 'i' || format == 'd')
		put_nbr_base(va_arg(*ptr, int), 10, "0123456789", count);
	else if (format == 'u')
		put_nbr_base(va_arg(*ptr, unsigned), 10, "0123456789", count);
	else if (format == 'c')
		ft_putchar(va_arg(*ptr, int), count);
	else if (format == 's')
		ft_process_str(va_arg(*ptr, char *), count);
	else if (format == 'x')
		put_nbr_base(va_arg(*ptr, unsigned int), 16, "0123456789abcdef", count);
	else if (format == 'X')
		put_nbr_base(va_arg(*ptr, unsigned int), 16, "0123456789ABCDEF", count);
	else if (format == '%')
		ft_putchar('%', count);
	else if (format == 'p')
		ft_putptr(va_arg(*ptr, unsigned long), count);
	else
		ft_putchar(format, count);
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
			check_letter_conversion(format[i + 1], &ptr, &count);
			i += 2;
		}
		else
		{
			ft_putchar(format[i], &count);
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

// 	printf(" %c %c %c ", '0', 0, '1');
// 	printf("\n");
// 	ft_printf(" %c %c %c ", '0', 0, '1');
// 	printf("Expected return value: %d\n", printf(" %c %c %c ", '0', 0, '1'));
// 	printf("Return value: %d\n", ft_printf(" %c %c %c ", '0', 0, '1'));

// 	printf(" %c %c %c ", '1', '2', '3');
// 		printf("\n");
// 	ft_printf(" %c %c %c ", '1', '2', '3');
// 	return (0);
// }
