/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:46:46 by jbarbay           #+#    #+#             */
/*   Updated: 2023/10/17 13:46:48 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif

int	ft_strlen(const char *string);
char	*ft_strjoin(char const *s1, char const *s2);
char *get_next_line(int fd);
int	has_new_line(char *buffer);
int	get_line(char *buffer, int size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
