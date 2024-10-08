/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_error_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:11:15 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/08 19:21:14 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execve_error_manager(char **cmd, char **all_envs, char *path)
{
	ft_putstr_fd(path, STDERR_FILENO);
	if ((*path == '/' || *path == '.') && directory_detector(path))
	{
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
		exit_status_holder(126, true);
	}
	else if (permission_denied_detector(path))
	{
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		exit_status_holder(126, true);
	}
	else if ((*path == '/' || *path == '.') && access(path, F_OK) == -1
		&& !directory_detector(path))
	{
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		exit_status_holder(127, true);
	}
	else if ((*path != '/' || *path != '.'))
	{
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit_status_holder(127, true);
	}
	if (path != cmd[0])
		free(path);
	clearing_execve_error_manager(cmd, all_envs);
}

bool	directory_detector(char *path)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == 0)
	{
		if (S_ISDIR(statbuf.st_mode) && access(path, F_OK) == 0)
			return (true);
	}
	return (false);
}

bool	permission_denied_detector(char *path)
{
	if (access(path, F_OK) == 0 && !directory_detector(path)
		&& (access(path, R_OK) == -1 || access(path, W_OK) == -1))
		return (true);
	return (false);
}

void	clearing_execve_error_manager(char **cmd, char **all_envs)
{
	free_array(all_envs);
	free_array(cmd);
	clear_all_to_exit_smoothly();
	exit(exit_status_holder(0, false));
}
