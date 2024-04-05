/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:33:11 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/05 16:52:56 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_cd(char **argv, int i)
{
	if (i != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		return ;
	}
	if (chdir(argv[1]) == -1)
	{
		printf("ERROR\n");
		write(2,  "error: cd: cannot change directory to ", 38);
		write(2, argv[1], ft_strlen(argv[1] + 1));
		write(2, "\n", 1);
	}
}

int	get_n_args(char **argv)
{
	int	i = 0;

	while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
		i++;
	return (i);
}

int main(int argc, char *argv[], char *envp[])
{
	int	status;
	int	i;
	int	n_args = 0;

	i = 0;
	if (argc == 1)
		return (0);
	
	while (argv[i] && argv[i + 1]) 
	{
		i++;
		argv += i;
		i = get_n_args(argv);

		if (strcmp(*argv, "cd") == 0)
			ft_cd(argv, i);

	}

	
	return (0);
}

// I start with argv[1]
//