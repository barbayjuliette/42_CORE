#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ptr = NULL;
	while (haystack[i] && (i + ft_strlen(needle) <= len))
	{
		if (haystack[i] == needle[j])
		{
			j++;
			i++;
		}
		else
		{
			if (j == 0)
				i++;
			else
				j = 0;
		}
	}
	if (!needle[j])
		ptr = (char *)&haystack[i - j];
	return (ptr);
}
