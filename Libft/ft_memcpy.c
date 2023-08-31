#include "libft.h"

void *ft_memcpy(void *dest, const void *src, int n)
{
	char *source;
	char *destination;
	int i;

	if (dest == NULL)
		return NULL;
	source = (char *)src;
	destination = (char *)dest;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
