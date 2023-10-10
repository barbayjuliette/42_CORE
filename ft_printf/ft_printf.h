/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:07:02 by jbarbay           #+#    #+#             */
/*   Updated: 2023/10/10 11:07:11 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

static int	count_args(const char *format);
int		ft_printf(const char *format, ...);
void	ft_put_unsigned_fd(unsigned int n, int fd);
void	ft_puthexa(unsigned long int n);
void	ft_puthexa_upcase(unsigned int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
