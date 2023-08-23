#include <stdio.h>
#include <string.h>
#include "libft.h"

int main(void)
{
	// ft_strlen
	printf("%s", "Test string length: ");
	char *word = "This is a test";
	strlen(word) == ft_strlen(word) ? printf("%s", "OK\n") : printf("%s", "NOK\n");
	printf("%s", "Test string length: ");
	strlen(word) == ft_strlen("hello") ? printf("%s", "NOK\n") : printf("%s", "OK\n");

	//ft_isalpha
	printf("%s", "Test isalpha: ");
	(ft_isalpha(97) > 0 && ft_isalpha(3) == 0) ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	// ft_isdigit
	printf("%s", "Test isdigit: ");
	(ft_isdigit('1') != 0 && ft_isdigit('8') != 0 && ft_isdigit('c') == 0 ) ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	// ft_isalnum
	printf("%s", "Test isalnum: ");
	(ft_isalnum('c') && ft_isalnum('6') && !ft_isalnum('(')) ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	// ft_isascii
	printf("%s", "Test isascii: ");
	(ft_isascii(99) && ft_isascii(0) && !ft_isascii(128)) ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	// ft_isprint
	printf("%s", "Test isprint: ");
	(ft_isprint(99) && ft_isprint(126) && !ft_isprint(132)) ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	// ft_toupper
	printf("%s", "Test isupper: ");
	(ft_toupper('a') == 'A' && ft_toupper('(') == '(' && ft_toupper('A')  == 'A') ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	// ft_tolower
	printf("%s", "Test islower: ");
	(ft_tolower('A') && ft_tolower('(')  == '(' && ft_tolower('z') == 'z') ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	return (0);
}
