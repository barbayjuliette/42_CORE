/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:46:53 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/14 11:47:00 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	no_path(char *path, char *cmd)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	free(path);
	exit(127);
}

void	handle_errors(int err, char *str)
{
	perror(str);
	exit(err);
}

void	handle_file_errors(int err, char *file)
{
	char	*error_msg;

	error_msg = ft_strdup(strerror(errno));
	if (*error_msg)
		*error_msg = ft_tolower(*error_msg);
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(file, 2);
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
