/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:30:58 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/21 15:31:02 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strjoin_2(char **map, char *buffer, int i, int j)
{
	char	*string;

	string = (char *)malloc((ft_strlen(*map) + ft_strlen(buffer) + 1)
			* sizeof(char));
	if (!string)
		return (MALLOC_ERROR);
	while ((*map)[i])
	{
		string[j] = (*map)[i];
		i++;
		j++;
	}
	i = 0;
	while (buffer[i])
	{
		string[j] = buffer[i];
		i++;
		j++;
	}
	string[j] = '\0';
	free(*map);
	*map = string;
	return (0);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	get_height(char *map)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			height++;
		i++;
	}
	if (map[i - 1] && map[i - 1] != '\n')
		height++;
	return (height);
}
