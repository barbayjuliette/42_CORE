#include "libft.h"

int	ft_strlen(const char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}
