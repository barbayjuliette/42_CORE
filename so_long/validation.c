/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:31:21 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/21 15:31:23 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char *map)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			height++;
		i++;
	}
	if (map[i - 1] && map[i - 1] != '\n')
		height++;
	return (height);
}

int	is_rectangle(char *map, int width)
{
	int	i;
	int	temp_width;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			if (temp_width != width)
				return (-1);
			temp_width = 0;
			i++;
		}
		else
		{
			temp_width++;
			i++;
		}
	}
	return (width);
}

int	get_width(char *map)
{
	int	i;
	int	width;
	int	temp_width;

	i = 0;
	width = 0;
	temp_width = 0;
	while (map[i] && map[i] != '\n')
	{
		width++;
		i++;
	}
	return (is_rectangle(map, width));
}

int	count_char_map(int *exit, int *start, int *collectible, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'E')
			(*exit)++;
		if (map[i] == 'P')
			(*start)++;
		if (map[i] == 'C')
			(*collectible)++;
		if (!(map[i] == 'E' || map[i] == 'C' || map[i] == 'P' || 
				map[i] == '0' || map[i] == '1' || map[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

int	check_characters(char *map, t_mlx_data *data)
{
	int	exit;
	int	start;
	int	collectible;

	exit = 0;
	start = 0;
	collectible = 0;
	if (!count_char_map(&exit, &start, &collectible, map))
		return (0);
	if (exit == 1 && start == 1 && collectible > 0)
	{
		data->collectibles = collectible;
		return (1);
	}
	return (0);
}

int	map_validation(char *map, t_mlx_data *data, char *filename)
{
	if (check_ber_file(filename) != 0)
		return (0);
	if (check_characters(map, data) && get_width(map))
		return (1);
	return (0);
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