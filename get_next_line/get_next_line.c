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

int	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	string = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		string[j] = s2[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substring;
	size_t		i;
	size_t		j;

	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			substring[j] = s[i];
			j++;
		}
		i++;
	}
	substring[j] = '\0';
	return (substring);
}
 
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
	return (-1);
}

char	*get_line(char *rem, int size)
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
		line[i] = rem[i];
		i++;
	}
	return (line);
}

char *get_next_line(int fd)
{
	char		*buffer;
	int			bytes_read;
	char 		*line;
	static char	*rem;
	int			index_line;

	buffer = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!rem)
		rem = (char *)malloc(sizeof(char) *(BUFFER_SIZE + 1));

	if (!buffer || fd < 0 || BUFFER_SIZE < 1 || !rem)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && has_new_line(rem) == -1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		rem = ft_strjoin(rem, buffer);
	}
	if (bytes_read == 0 && rem[0] == '\0')
		return (NULL);
	index_line = has_new_line(rem);
	if (index_line != -1)
	{
		line = get_line(rem, index_line + 1);
		rem = ft_substr(rem, index_line + 1, ft_strlen(rem) - index_line);
	}
	else
	{
		line = rem;
		rem = ft_substr(rem, 0, 0);
	}
	return (line);
}

int main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("First call: %s\n", get_next_line(fd));
	printf("Second call: %s\n", get_next_line(fd));
	printf("Third call: %s\n", get_next_line(fd));
	printf("Forth call: %s\n", get_next_line(fd));
	printf("Fifth call: %s\n", get_next_line(fd));
	printf("Sixth call: %s\n", get_next_line(fd));
	printf("Seventh call: %s\n", get_next_line(fd));
	printf("Eigth call: %s\n", get_next_line(fd));
	// printf("%s", get_next_line(fd));

	close(fd);
	return (0);
}