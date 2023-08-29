#include "libft.h"

int	ft_strlcpy(char * restrict dest, const char * restrict src, int destsize)
{
	int	i;

	i = 0;
	if (destsize == 0)
		return (ft_strlen(src));
	while (i < destsize - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
