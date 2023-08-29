#include "libft.h"

int	ft_strlcpy(char * restrict dest, const char * restrict src, int destsize)
{
	int	i;

	i = 0;
	if (destsize == 0) // it tried to create a string of src_size, but failed. Return the size of src.
		return (ft_strlen(src));

	// While there is space in dest, we copy from source to dest. We keep space for the terminating character, hence size - 1
	while (i < destsize - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}

	// if (i < destsize)
		dest[i] = '\0';

	// return the total length of the string it tried to create
	return (ft_strlen(src));
}
