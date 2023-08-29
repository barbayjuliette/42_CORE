#include "libft.h"

int	ft_strlcat(char *dest, const char *src, int destsize)
{
	int	dest_len;
	int	src_len;
	int	i;
	int	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	j = 0;
	if (destsize < dest_len)
		return (src_len + destsize);

	while (src[j] && j < destsize - dest_len - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}
