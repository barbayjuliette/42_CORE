#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	int	i;
	char *string;

	i = 0;
	string = (char *)s;
	while (string[i] && i < n)
	{
		if (string[i] == c)
			return (string + i);
		i++;
	}
	return (NULL);
}
