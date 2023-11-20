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
	if (map[i-1] && map[i-1] != '\n')
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
	while ( map[i] && map[i] != '\n')
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
		if (!(map[i] == 'E' || map[i] == 'C' || map[i] == 'P' || map[i] == '0'|| map[i] == '1' || map[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

int	check_characters(char *map)
{
	int	exit;
	int	start;
	int collectible;

	exit = 0;
	start = 0;
	collectible = 0;
	if (!count_char_map(&exit, &start, &collectible, map))
		return (0);
	if (exit == 1 && start == 1 && collectible > 0)
		return (1);
	return (0);
}

int	map_validation(char *map)
{
	printf("HEIGHT: %d\n", get_height(map));
	printf("WIDTH: %d\n", get_width(map));
	if (check_characters(map) && get_width(map))
		return (1);
	return (0);
}
