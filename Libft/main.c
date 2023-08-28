#include <stdio.h>
#include <string.h>
#include "libft.h"

int	main(void)
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

	// ft_strncmp
	printf("%s", "Test strncmp: ");
	char *s1 = "abce";
	char *s2 = "abcd";
	ft_strncmp(s1, s2, 3) == strncmp(s1, s2, 3) ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	// ft_putchar_fd
	printf("%s", "Test putchar: ");
	fflush(stdout);
	ft_putchar_fd('O', 1);
	ft_putchar_fd('K', 1);
	write(1, "\n", 1);

	// ft_putstr_fd
	char *string = "Putstr is: OK";
	ft_putstr_fd(string, 1);
	write(1, "\n", 1);

	// ft_putendl
	char *string2 = "Putstr with new line is: OK";
	ft_putendl_fd(string2, 1);

	// ft_atoi
	printf("%s", "Test atoi: ");
	ft_atoi("-423") == atoi("-423") && ft_atoi("123456") == atoi("123456") ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	// ft_strnstr
	char needle[] = "jul";
	char haystack[] = "juliette";
	printf("%s", "Test stnstr 1: ");
	strnstr(haystack, needle, 5) == ft_strnstr(haystack, needle, 5) ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	char substring[] = "jul";
	char search_string[] = "juliette";
	printf("%s", "Test stnstr 2: ");
	strnstr(search_string, substring, 5) == ft_strnstr(search_string, substring, 5) ? printf("%s", "OK\n") : printf("%s", "NOK\n");


	// ft_strstr
	char strstr[] = "abbc";
	printf("%s", "Test strstr 1: ");
	strchr(strstr, '\0') == ft_strchr(strstr, '\0') ? printf("%s", "OK\n") : printf("%s", "NOK\n");
	printf("%s", "Test strstr 2: ");
	strchr(strstr, 'c') == ft_strchr(strstr, 'c') ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	// ft_strrstr
	printf("%s", "Test strrstr 1: ");
	strrchr(strstr, '\0') == ft_strrchr(strstr, '\0') ? printf("%s", "OK\n") : printf("%s", "NOK\n");
	printf("%s", "Test strrstr 2: ");
	strrchr(strstr, 'x') == ft_strrchr(strstr, 'x') ? printf("%s", "OK\n") : printf("%s", "NOK\n");

	return (0);
}
