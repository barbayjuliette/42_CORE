/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:58 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/21 15:31:02 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

int	ft_strjoin(char **map, char *buffer, int i, int j)
{
	char	*string;

	string = (char *)malloc((ft_strlen(*map) + ft_strlen(buffer) + 1) * sizeof(char));
	if (!string)
		return (MALLOC_ERROR);
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
	return (0);
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

// char	**create_matrix(int height)
// {
// 	char	**matrix;

// 	matrix = (char **)malloc(height * (sizeof(char *) + 1));
// 	if (!matrix)
// 		exit(1);
// 	return (matrix);
// }

// char	**populate_input_matrix(t_mlx_data *data, char *buff, int j)
// {
// 	char	*matrix_row;
// 	int		row_index;
// 	char	**matrix;
// 	int		col;

// 	matrix = create_matrix(data->map_height);
// 	col = 0;
// 	while (++j < data->map_height)
// 	{
// 		matrix_row = (char *)malloc((data->map_width + 1) * sizeof(char));
// 		if (!matrix_row)
// 			exit(1);
// 		row_index = 0;
// 		while (row_index < data->map_width)
// 		{
// 			if (buff[col] == '\n' || buff[col] == '\0')
// 				col++;
// 			if (buff[col] == 'P')
// 			{
// 				data->position[1] = row_index;
// 				data->position[0] = j;
// 			}
// 			matrix_row[row_index] = buff[col];
// 			col++;
// 			row_index++;
// 		}
// 		matrix_row[row_index] = '\0';
// 		matrix[j] = matrix_row;
// 	}
// 	matrix[j] = "\0";
// 	return (matrix);
// }
