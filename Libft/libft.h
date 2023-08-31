#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(const char *string);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_tolower(int c);
int	ft_toupper(int c);
int	ft_strncmp(const char *s1, const char *s2, int n);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
int	ft_atoi(const char *str);
int	ft_strlcpy(char *restrict dest, const char * restrict src, int dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
int		ft_strlcat(char *dest, const char *src, int destsize);
void	*ft_memset(void *b, int c, int len);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *dest, const void *src, int n);
void	*ft_memccpy(void *restrict dest, const void *restrict src, int c, int n);
void	*ft_memchr(const void *s, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_memmove(void *dest, const void *src, int len);
char	*ft_strdup(const char *s1);
void	*ft_calloc(int count, int size);
char	*ft_itoa(int num);

#endif
