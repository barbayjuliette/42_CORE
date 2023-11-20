#include "so_long.h"

int	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

void	ft_strjoin(char **map, char *buffer, int i, int j)
{
	char	*string;

	string = (char *)malloc((ft_strlen(*map) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!string)
		return ;
	while ((*map)[i])
	{
		string[j] = (*map)[i];
		i++;
		j++;
	}
	i = 0;
	while (buffer[i])
	{
		string[j] = buffer[i];
		i++;
		j++;
	}
	string[j] = '\0';
	free(*map);
	*map = string;
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int get_map_and_validate(int argc, char *argv[])
{
	int	fd;
	char	*buffer;
	int		bytes_read;
	char	*map;

	if (argc != 2)
	{
		ft_putstr("Error, where is the map?\n");
		exit(1);
	}

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	map = (char *)malloc(sizeof(char));
	map[0] = '\0';
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		ft_putstr("Sorry, I couldn't read the file you gave me.\n");
		exit(1);
	}

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_putstr("Oops, I am having trouble while reading the file.\n");
			free(buffer);
			free(map);
			exit(1);
		}
		buffer[bytes_read] = '\0';
		ft_strjoin(&map, buffer, 0, 0);
	}
	free(buffer);
	if (!(map_validation(map)))
	{
		ft_putstr("Map not valid\n");
		return (1);
	}
	ft_putstr("Valid map\n");
	free(map);
	close(fd);

	return (0);
}