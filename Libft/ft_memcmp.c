#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, int n)
{
	int	i;
	char *string1;
	char *string2;

	string1 = (char *)s1;
	string2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (string1[i] != string2[i])
			return ((unsigned char)string1[i] - (unsigned char)string2[i]);
		i++;
	}
	return (0);
}
