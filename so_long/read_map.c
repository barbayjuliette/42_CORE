/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:10 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/21 15:31:13 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int get_map_and_validate(int argc, char *argv[], t_mlx_data *data)
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
	if (!(map_validation(map, data)))
	{
		ft_putstr("Map not valid\n");
		return (1);
	}
	// ft_putstr("Valid map\n");
	data->map_width = get_width(map);
	data->map_height = get_height(map);
	data->map = populate_input_matrix(data, map, -1);
	if (!check_walls(data->map, data->map_height, data->map_width))
	{
		ft_putstr("Map not valid\n");
		return (1);
	}
	ft_putstr("Valid map\n");
	// print_matrix(data->map, data->map_height, data->map_width);
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

// void print_matrix(char **matrix, int rows, int cols) {
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) 
// 		{
//             write(1, &matrix[i][j], 1);
//         }
//         write(1, "\n", 1);
//     }
// }
