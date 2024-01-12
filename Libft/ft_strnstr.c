/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:11:17 by jbarbay           #+#    #+#             */
/*   Updated: 2023/09/06 12:11:20 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
		int	i;
		int	needle_length;

		if (*needle == '\0')
			return ((char *)haystack);
		i = 0;
		needle_length = ft_strlen(needle);
		while (haystack[i] && i + needle_length <= len)
		{
			if (ft_strncmp(haystack + i, needle, needle_length) == 0)
				return ((char *)haystack + i);
			i++;
		}
		return (NULL);
}

int main(int argc, char const *argv[])
{
	char *ptr = ft_strnstr("helloyoux", "you",  10);
	printf("Pointer: %s", ptr);
	return 0;
}
