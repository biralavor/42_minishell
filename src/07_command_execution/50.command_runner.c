/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   50.command_runner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:51:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/03 15:58:56 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_and_execve(char **cmd, char *path)
{
	char	**all_envs;
	pid_t	pid;

	all_envs = convert_envs_to_array(env_holder(NULL, false, false));
	if (child_process_is_running(false, true))
	{
		printf("True da true\n");
		env_holder(NULL, false, true);
		rl_clear_history();
	}
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
	child_process_is_running(true, false);
	free_array(all_envs);
	free(path);
}

void	execve_error_manager(char **cmd, char **all_envs, char *path)
{
	ft_putstr_fd(path, STDERR_FILENO);
	if ((*path == '/' || *path == '.') && !access(path, F_OK))
	{
		ft_putstr_fd(": Is a directory\n", STDERR_FILENO);
		exit_status_holder(126, true);
	}
	else if ((*path != '/' || *path != '.'))
	{
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit_status_holder(127, true);
	}
	else if (access(path, R_OK | W_OK) == -1 && !access(path, F_OK))
	{
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
		exit_status_holder(126, true);
	}
	else if (access(path, F_OK) == -1)
	{
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
		exit_status_holder(127, true);
	}
	free_array(all_envs);
	free(path);
	free(cmd);
	clear_all_to_exit_smoothly();
	exit(exit_status_holder(0, false));
}

char	*lookup_cmd_path(char *cmd_name)
{
	char		**all_paths;
	char		*to_execute;
	t_env_entry	*env_path;

	to_execute = NULL;
	env_path = lookup_table(env_holder(NULL, false, false), "PATH");
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

int	command_runner(char **cmd)
{
	int		exit_status;
	char	*path;

	path = NULL;
	exit_status = 0;
	path = lookup_cmd_path(cmd[0]);
	if (path)
		fork_and_execve(cmd, path);
	return (exit_status);
}

bool	directory_detector(char *path)
{
	struct stat	statbuf;
	int			status;

	status = stat(path, &statbuf);
	if (path[0] == '/' || (path[0] == '.' && path[1] == '/'))
	{
		if (S_ISDIR(statbuf.st_mode))
		return (true);
	}
	else if (status == -1)
		return (false);
	return (false);
}

bool	permission_denied_detector(char *path)
{
	if (access(path, X_OK) == -1)
		return (true);
	return (false);
}