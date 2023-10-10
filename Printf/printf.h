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


#ifndef PRINTF_H
# define PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"

static int	count_args(const char *format);
int		ft_printf(const char *format, ...);
int 	main(void);
void	ft_put_unsigned_fd(unsigned int n, int fd);
void	ft_puthexa(unsigned int n);
void	ft_puthexa_upcase(unsigned int n);

#endif
