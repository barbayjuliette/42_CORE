#include "libft.h"

void *ft_memset(void *b, int c, int len)
{
	int i;
	char *ptr;

	i = 0;
	ptr = (char *)b;
	while (i < len)
	{
		ptr[i] = (char)c;
		i++;
	}
	return (b);
}
