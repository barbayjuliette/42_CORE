#include "libft.h"

char *ft_substr(char const *s, int start, int len)
{
	char *substring;
	int	i;

	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);

	i = 0;
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}


// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*str;

// 	str = (char *)malloc(sizeof(*s) * (len + 1));
// 	if (str == 0)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (i >= start && j < len)
// 		{
// 			str[j] = s[i];
// 			j++;
// 		}
// 		i++;
// 	}
// 	str[j] = 0;
// 	return (str);
// }


//	if (start + len > ft_strlen(s))
// 		len = ft_strlen(s) - start;>
