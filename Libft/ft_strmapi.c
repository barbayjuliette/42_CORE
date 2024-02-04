/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:48:06 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/04 18:28:58 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.

#include "libft.h"

// static char	f(unsigned int i, char c)
// {
// 	c = ft_toupper(c);
// 	return (c);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(s);
	string = (char *)malloc((length + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (s[i])
	{
		string[i] = f(i, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}

// int	main(void)
// {
// 	char	*string;

// 	string = ft_strmapi("hello", f);
// 	printf("%s\n", string);
// 	return 0;
// }
