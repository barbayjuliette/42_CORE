#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int len)
{
	char *source;
	char *destination;

	source = (char *)src;
	destination = (char *)dest;
	if (dest < src)
		return (ft_memcpy(dest, src, len));
	else
	{
		while (len > 0)
		{
			len--;
			destination[len] = source[len];
		}
	}
	return (dest);
}
