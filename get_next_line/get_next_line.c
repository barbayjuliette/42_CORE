/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:46:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/10/17 13:46:11 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>


int	has_new_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*get_line(char *buffer, int size)
{
	char *line;
	int	i;

	line = (char *)malloc(sizeof(char) * (size + 1));
	if (!line)
		return (NULL);
	line[size] = '\0';
	i = 0;
	while (i < size)
	{
		line[i] = buffer[i];
		i++;
	}
	return (line);
}

char *get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0)
		return (NULL);
	else
	{
		if (has_new_line(buffer))
		{
			return (get_line(buffer, has_new_line(buffer) + 1));
		}
		else
		{
			// get_next_line(fd);
			return "hello";
		}
		// Check if buffer contains new line
			// YES: 
			// return the line till \n
			//  Create string with malloc, return that string
			// NO: Call get next line again
	}
}

int main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%d\n", fd );
	printf("%s", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}