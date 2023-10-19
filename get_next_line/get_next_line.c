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
	char	*line;
	int		i;

	if (size == 0)
		return (rem);
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

char	*ft_free(char *buffer)
{
	free(buffer);
	return (NULL);
}

int	read_file(char **rem, char **buffer, int fd)
{
	int	bytes_read;

	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	(*buffer)[bytes_read] = '\0';
	*rem = ft_strjoin(*rem, *buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bytes_read;
	char		*line;
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
		bytes_read = read_file(&rem, &buffer, fd);
		if (bytes_read < 0)
			return (ft_free(buffer));
	}
	free(buffer);
	if (bytes_read == 0 && rem[0] == '\0')
		return (ft_free(rem));
	index_line = has_new_line(rem);
	line = get_line(rem, index_line + 1);
	rem = ft_substr(rem, index_line + 1, ft_strlen(rem) - index_line);
	return (line);
}

int	main(void)
{
	int	fd;
	char *line;
	fd = open("test.txt", O_RDONLY);

	// while (line = get_next_line(fd))
	// {
	// 	printf("%s", line);
	// 	free(line);
	// }
	// free(line);

	printf("First call: %s", get_next_line(fd));
	printf("Second call: %s", get_next_line(fd));
	printf("Third call: %s", get_next_line(fd));
	printf("Forth call: %s", get_next_line(fd));
	printf("Fifth call: %s", get_next_line(fd));
	printf("Sixth call: %s", get_next_line(fd));
	printf("Seventh call: %s", get_next_line(fd));
	printf("Eigth call: %s", get_next_line(fd));
	printf("Nineth call: %s", get_next_line(fd));
	printf("xth call: %s", get_next_line(fd));
	printf("xth call: %s", get_next_line(fd));
	printf("xth call: %s", get_next_line(fd));
	printf("xth call: %s", get_next_line(fd));
	close(fd);

	return (0);
}