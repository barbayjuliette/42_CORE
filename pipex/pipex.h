/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay<marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:26:03 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/07 14:26:10 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

void	child_process_1(char *file, int fd[2], char *cmd, char **envp);
void	child_process_2(char *file, int fd[2], char *cmd, char **envp);
char	*get_path(char **envp, char *cmd);
char	*get_all_paths(char **envp);
void	handle_errors(int err, char *str);
void	no_path(char *path, char *cmd);
void	nb_args(int argc);
void	handle_file_errors(int err, char *file);
void	wait_child(int pid);

#endif
