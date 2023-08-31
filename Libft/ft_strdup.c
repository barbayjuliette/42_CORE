#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int	len;
	int	i;
	char	*copy;

	len = ft_strlen(s1);
	i = 0;
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';

	return (copy);
}
