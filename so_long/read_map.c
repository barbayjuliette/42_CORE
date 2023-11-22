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
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	close(fd);
	if (!(map_validation(map, data)))
	{
		ft_putstr("Map not valid\n");
		free(map);
		return (1);
	}
	data->map_width = get_width(map);
	data->map_height = get_height(map);
	data->map = ft_split(map, '\n');
	get_position_player(data);
	if (!check_walls(data->map, data->map_height, data->map_width))
	{
		ft_putstr("Map not valid\n");
		free_matrix(data->map, data->map_width, data->map_height);
		free(map);
		return (1);
	}
	ft_putstr("Valid map\n");
	free(map);
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
			col++;
		}
		row++;
	}
}
