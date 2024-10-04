/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   50.command_runner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:51:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/04 19:18:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_and_execve(char **cmd, char *path)
{
	char	**all_envs;
	pid_t	pid;

	all_envs = convert_envs_to_array(env_holder(NULL, false, false));
	if (child_process_is_running(false, true))
		env_holder(NULL, false, true);
	pid = fork();
	if (pid < 0)
		fork_error();
	child_process_is_running(true, true);
	if (pid == 0)
	{
		exit_status_holder(execve(path, cmd, all_envs), true);
		if (exit_status_holder(0, false) != 0)
			execve_error_manager(cmd, all_envs, path);
	}
	pid_exit_status_caller(pid);
	child_process_is_running(false, false);
	free_array(all_envs);
	free(path);
}

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
	clearing_execve_error_manager(cmd, all_envs, path);
}

char	*lookup_cmd_path(char *cmd_name)
{
	char		**all_paths;
	char		*to_execute;
	t_env_entry	*env_path;

	to_execute = NULL;
	env_path = lookup_table(env_holder(NULL, false, false), "PATH");
	if (env_path)
		all_paths = ft_split(env_path->value, ':');
	if (!is_cmd_with_valid_path(cmd_name))
	{
		to_execute = testing_all_paths_with_cmd(all_paths, cmd_name);
		free_array(all_paths);
		return (to_execute);
	}
	else
	{
		free_array(all_paths);
		return (cmd_name);
	}
}

void	command_runner(char **cmd)
{
	char	*path;

	path = NULL;
	path = lookup_cmd_path(cmd[0]);
	if (path)
		fork_and_execve(cmd, path);
}

bool	directory_detector(char *path)
{
	struct stat	statbuf;

	stat(path, &statbuf);
	if (S_ISDIR(statbuf.st_mode) && access(path, F_OK) == 0)
		return (true);
	return (false);
}

bool	permission_denied_detector(char *path)
{
	if (access(path, F_OK) == 0 && !directory_detector(path)
		&& (access(path, R_OK) == -1 || access(path, W_OK) == -1))
		return (true);
	return (false);
}

void	clearing_execve_error_manager(char **cmd, char **all_envs, char *path)
{
	free_array(all_envs);
	free(path);
	free(cmd);
	clear_all_to_exit_smoothly();
	exit(exit_status_holder(0, false));
}
