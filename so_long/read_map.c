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
	char	**matrix;

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
	// ft_putstr("Valid map\n");
	matrix = populate_input_matrix(get_height(map), get_width(map), map, -1);
	if (!check_walls(matrix, get_height(map), get_width(map)))
	{
		ft_putstr("Map not valid\n");
		return (1);
	}
	ft_putstr("Valid map\n");
	// print_matrix(matrix, get_height(map), get_width(map));
	free(map);
	close(fd);

	return (0);
}

int	check_walls(char **matrix, int height, int width)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < height)
	{
		while (col < width)
		{
			if (row == 0 && matrix[row][col] != '1')
				return (0);
			if (row == height - 1 && matrix[row][col] != '1')
				return (0);
			if (col == 0 && matrix[row][col] != '1')
				return (0);
			if (col == width - 1 && matrix[row][col] != '1')
				return (0);
			col++;
		}
		col = 0;
		row++;
	}
	return (1);
}

char	**create_matrix(int height)
{
	char	**matrix;

	matrix = (char **)malloc(height * sizeof(char *));
	if (!matrix)
		exit(1);
	return (matrix);
}

char	**populate_input_matrix(int height, int width, char *buff, int j)
{
	char	*matrix_row;
	int		row_index;
	char	**matrix;
	int		col;

	matrix = create_matrix(height);
	col = 0;
	while (++j < height)
	{
		matrix_row = (char *)malloc((width + 1) * sizeof(char));
		if (!matrix_row)
			exit(1);
		row_index = 0;
		while (row_index < width)
		{
			if (buff[col] == '\n')
				col++;
			matrix_row[row_index] = buff[col];
			col++;
			row_index++;
		}
		matrix_row[row_index] = '\0';
		matrix[j] = matrix_row;
	}
	return (matrix);
}
// void print_matrix(char **matrix, int rows, int cols) {
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) 
// 		{
//             write(1, &matrix[i][j], 1);
//         }
//         write(1, "\n", 1);
//     }
// }