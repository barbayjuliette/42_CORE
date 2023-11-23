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

void	read_file(char **map, char *filename)
{
	int		fd;
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(*map);
		exit(MALLOC_ERROR);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_file(*map, buffer, "Could not find file.\n");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			error_file(buffer, *map, "Error reading file.\n");
		buffer[bytes_read] = '\0';
		ft_strjoin_2(map, buffer, 0, 0);
	}
	free(buffer);
	close(fd);
}

int	get_map_and_validate(int argc, char *argv[], t_mlx_data *data)
{
	char	*map;
	char	**matrix;

	if (argc != 2)
	{
		ft_putstr("Error\nWhere is the map?\n");
		exit(1);
	}
	map = (char *)malloc(sizeof(char));
	if (!map)
		exit(MALLOC_ERROR);
	map[0] = '\0';
	read_file(&map, argv[1]);
	if (!map_validation_1(map, data, argv[1]))
	{
		free(map);
		return (1);
	}
	add_mlx_data(data, map);
	call_valid_path(map, data);
	call_check_walls(data);
	return (0);
}

void	call_check_walls(t_mlx_data *data)
{
	if (!check_walls(data->map, data->map_height, data->map_width))
	{
		ft_putstr("Error\nThe map must be surrounded by walls.\n");
		free_matrix(data->map);
		exit(1);
	}
}

void	error_file(char *buffer, char *map, char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
	free(buffer);
	free(map);
	exit(1);
}

void	get_position_player(t_mlx_data *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < data->map_height)
	{
		col = 0;
		while (col < data->map_width)
		{
			if (data->map[row][col] == 'P')
			{
				data->position[0] = row;
				data->position[1] = col;
			}
			if (data->map[row][col] == 'E')
			{
				data->pos_exit[0] = row;
				data->pos_exit[1] = col;
			}
			col++;
		}
		row++;
	}
}
