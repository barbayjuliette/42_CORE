/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:38:29 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/08 12:38:32 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_2(char *file, int fd[2], char *cmd, char **envp)
{
	int		outfile;
	char	**command2;
	char	*path;

	outfile = open(file, O_WRONLY | O_CREAT | O_TRUNC, 00777);
	if (outfile == -1)
		handle_errors(errno, "pipex");
	if (dup2(outfile, 1) == -1)
		handle_errors(errno, "pipex");
	if (dup2(fd[0], 0) == -1)
		handle_errors(errno, "pipex");
	close(fd[0]);
	close(fd[1]);
	command2 = ft_split(cmd, ' ');
	path = get_path(envp, command2[0]);
	if (path)
		execve(path, command2, envp);
	free(command2);
	if (!path)
		no_path(path);
	free(path);
	handle_errors(errno, "pipex");
	return ;
}

void	no_path(char *path)
{
	ft_putstr_fd("pipex: command not found\n", 2);
	free(path);
	exit(127);
}

void	handle_errors(int err, char *str)
{
	perror(str);
	exit(err);
}

char	*get_all_paths(char **envp)
{
	int		i;
	char	*path;

	if (!(*envp))
		return ("/usr/sbin:/usr/bin:/sbin:/bin");
	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
	return (path);
}

char	*get_path(char **envp, char *cmd)
{
	int		i;
	char	*path;
	char	**all_paths;
	char	*command;

	all_paths = ft_split(get_all_paths(envp), ':');
	i = 0;
	while (all_paths[i])
	{
		command = ft_strjoin("/", cmd);
		path = ft_strjoin(all_paths[i], command);
		free(command);
		if (access(path, F_OK) == 0)
		{
			free(all_paths);
			return (path);
		}
		free(path);
		i++;
	}
	free(all_paths);
	return (NULL);
}
