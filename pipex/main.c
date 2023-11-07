/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay<marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:16:01 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/07 14:16:21 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
	{
		ft_printf("Wrong number of arguments. Please try again.\n");
		return (1);
	}

	char	*infile;
	char	*outfile;
	char	**command1;
	char	*command2;

	infile = argv[1];
	command1 = ft_split(argv[2], ' ');
	command2 = argv[3];
	outfile = argv[4];

	int i = 0;

	// while (command1[i])
	// {
	// 	ft_putstr_fd(command1[i], 1);
	// 	free(command1[i]);
	// 	write(1, "\n", 1);
	// 	i++;
	// }
	// write(1, "Hello\n", 6);

	return 0;
}
