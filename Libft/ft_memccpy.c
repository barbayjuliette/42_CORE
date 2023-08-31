#include "libft.h"

void	*ft_memccpy(void *restrict dest, const void *restrict src, int c, int n)
{
	char *source;
	char *destination;
	int i;

	source = (char *)src;
	destination = (char *)dest;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		if (source[i] == c)
			return (destination + i + 1);
		i++;
	}
	return (NULL);
}
