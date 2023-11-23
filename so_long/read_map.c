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
	int		fd;
	char	*buffer;
	int		bytes_read;
	char	*map;
	char	**matrix;

	if (argc != 2)
	{
		ft_putstr("Error\nWhere is the map?\n");
		exit(1);
	}
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		exit(MALLOC_ERROR);
	map = (char *)malloc(sizeof(char));
	map[0] = '\0';
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_file(map, buffer, "Sorry, I couldn't read the file you gave me.\n");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			error_file(buffer, map, "I am having trouble while reading the file.\n");
		buffer[bytes_read] = '\0';
		ft_strjoin_2(&map, buffer, 0, 0);
	}
	free(buffer);
	close(fd);
	if (!map_validation_1(map, data, argv[1]))
	{
		free(map);
		return (1);
	}
	add_mlx_data(data, map);
	call_valid_path(map, data);
	if (!check_walls(data->map, data->map_height, data->map_width))
	{
		ft_putstr("Error\nThe map must be surrounded by walls.\n");
		free_matrix(data->map);
		return (1);
	}
	return (0);
}

void	error_file(char *buffer, char *map, char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
	free(buffer);
	free(map);
	exit(1);
}

void	call_valid_path(char *map, t_mlx_data *data)
{
	char **test_map;
	
	test_map = ft_split(map, '\n');
	if (!valid_path(test_map, data))
	{
		ft_putstr("Error\nThere is no valid path\n");
		free_matrix(data->map);
		free_matrix(test_map);
		free(map);
		exit(1);
	}
	free(map);
	free_matrix(test_map);
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

void print_matrix(char **matrix, int rows, int cols) 
{
	int	row = 0;
	int	col = 0;

	while (row < rows)
	{
		ft_putstr(matrix[row]);
		write(1, "\n", 1);
		row++;
	}
}

void	get_position_player(t_mlx_data *data)
{
	int	row = 0;
	int	col = 0;

	while (row < data->map_height)
	{
		col = 0;
		while (col < data->map_width)
		{
			if ( data->map[row][col] == 'P')
			{
				data->position[0] = row;
				data->position[1] = col;
			}
			if ( data->map[row][col] == 'E')
			{
				data->pos_exit[0] = row;
				data->pos_exit[1] = col;
			}
			col++;
		}
		row++;
	}
}

void	flood_fill(char **map, int row, int col)
{
	if (map[row][col] == 'C' || map[row][col] == '0' ||  map[row][col] == 'P')
	{
		map[row][col] = 'X';
		flood_fill(map, row + 1, col);
	 	flood_fill(map, row - 1, col);
		flood_fill(map, row, col + 1);
		flood_fill(map, row, col - 1);
	}
	else
		return ; 
}

int	valid_path(char **filled_map, t_mlx_data *data)
{
	int	row = 0;
	int	col = 0;
	int	exit_row;
	int	exit_col;

	flood_fill(filled_map, data->position[0],  data->position[1]);
	exit_row = data->pos_exit[0];
	exit_col = data->pos_exit[1];
	while (row < data->map_height)
	{
		col = 0;
		while (col < data->map_width)
		{
			if (filled_map[row][col] == 'C')
				return (0);
			col++;
		}
		row++;
	}
	if (filled_map[exit_row + 1][exit_col] == 'X' || filled_map[exit_row - 1][exit_col] == 'X' || filled_map[exit_row][exit_col + 1] == 'X' || filled_map[exit_row][exit_col - 1] == 'X')
		return (1);
	return (0);
}