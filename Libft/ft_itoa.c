#include "libft.h"

static int	get_length_num(long num)
{
	int	length;

	length = 1;
	if (num < 0)
	{
		length++;
		num = -num;
	}
	while (num > 9)
	{
		num = num / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int	len;
	char *string;
	int	digit;
	long num;

	num = n;
	len = get_length_num(num);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	string[len] = '\0';
	len--;
	if (num < 0)
	{
		num = -num;
		string[0] = '-';
	}
	while (num > 9)
	{
		digit = num % 10;
		num = num / 10;
		string[len] = '0' + digit;
		len--;
	}
	string[len] = '0' + num;
	return (string);
}
