#include "so_long.h"

static	int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	get_length_word(char const *str, char c)
{
	int	length;

	length = 0;
	while (str[length] != c && str[length])
		length++;
	return (length);
}

static char	*get_word(char const *str, char c)
{
	int		i;
	char	*word;
	int		length;

	length = get_length_word(str, c);
	word = (char *)malloc((length + 1) * sizeof(char));
	i = 0;
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	int		total_words;
	char	**strings;
	int		j;

	total_words = count_words(s, c);
	strings = (char **)malloc((total_words + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			strings[j] = get_word(s, c);
			s = s + get_length_word(s, c);
			j++;
		}
	}
	strings[j] = NULL;
	return (strings);
}