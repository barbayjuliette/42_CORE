#include "push_swap.h"

void	free_matrix(char **map)
{
	int	row;

	row = 0;
	while (map[row])
	{
		free(map[row]);
		row++;
	}
	free(map);
}
