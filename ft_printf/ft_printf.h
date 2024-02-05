/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:07:02 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/05 17:03:40 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
// # include <stdio.h>

int			ft_printf(const char *format, ...);
void		ft_putchar(char c, int *count);
void		ft_putstr(char *s, int *count);
void		ft_putptr(unsigned int num, int *count);
void		ft_process_str(char *str, int *count);
void		check_letter_conversion(char format, va_list *ptr, int *count);
void		put_nbr_base(long long int num, int len, char *base, int *count);

#endif
