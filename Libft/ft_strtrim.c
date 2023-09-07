/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:17:20 by jbarbay           #+#    #+#             */
/*   Updated: 2023/09/06 16:17:26 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_trim(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_char_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (to_trim(s1[i], set))
		i++;
	return (i);
}

static int	count_char_end(char const *s1, char const *set)
{
	int	i;
	int	count;

	i = ft_strlen(s1) - 1;
	count = 0;
	while (to_trim(s1[i], set))
	{
		i--;
		count++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*string;

	len = ft_strlen(s1) - count_char_end(s1, set) - count_char_start(s1, set);
	string = ft_substr(s1, count_char_start(s1, set), len);
	return (string);
}

// int main(void)
// {
// 	printf("%s\n", ft_strtrim("hhsblahs", "hs"));
// 	return(0);
// }
