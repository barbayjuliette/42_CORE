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
  return (0);
}
