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

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_process_int(int num);
static int	count_args(const char *format);
int			ft_printf(const char *format, ...);
void		ft_put_unsigned_fd(unsigned int n, int fd);
int			ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_putstr_fd(char *s, int fd);
int			get_length_num(long num);
int			ft_puthexa(unsigned long int n);
int			ft_puthexa_upcase(unsigned long int n);
int			ft_putptr(unsigned long int num);
int			get_length_unsigned(unsigned int num);
int			ft_count_n_hexa(unsigned long int n);

#endif
