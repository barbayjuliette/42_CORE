/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:14:27 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/23 18:14:32 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int row, int col)
{
	if (map[row][col] == 'C' || map[row][col] == '0' || map[row][col] == 'P')
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

int	valid_path(char **flood, t_mlx_data *data)
{
	int	row;
	int	col;
	int	i;
	int	j;

	row = 0;
	col = 0;
	i = data->pos_exit[0];
	j = data->pos_exit[1];
	flood_fill(flood, data->position[0], data->position[1]);
	while (row < data->map_height)
	{
		col = 0;
		while (col < data->map_width)
		{
			if (flood[row][col] == 'C')
				return (0);
			col++;
		}
		row++;
	}
	if (flood[i + 1][j] == 'X' || flood[i - 1][j] == 'X' 
		|| flood[i][j + 1] == 'X' || flood[i][j - 1] == 'X')
		return (1);
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

void	call_valid_path(char *map, t_mlx_data *data)
{
	char	**test_map;

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

int	check_ber_file(char *filename)
{
	int	length;
	int	result;

	length = ft_strlen(filename);
	filename += (length - 4);
	result = ft_strncmp(filename, ".ber", 4);
	filename -= (length - 4);
	return (result);
}
