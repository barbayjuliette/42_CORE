#include "libft.h"

void	*ft_calloc(int count, int size)
{
	char	*string;

	string = malloc(count * size);
	ft_bzero(string, count);
	return (string);
}
