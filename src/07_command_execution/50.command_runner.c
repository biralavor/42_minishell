/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   49.command_runner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:51:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/16 12:06:12 by umeneses         ###   ########.fr       */
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
		env_holder(NULL, false, true);
		rl_clear_history();
	}
	pid = fork();
	if (pid == -1)
		fork_error();
	child_process_is_running(true, true);
	if (pid == 0)
	{
		exit_status_holder(execve(path, cmd, all_envs), true);
		if (exit_status_holder(0, false) != 0)
			execve_error_manager(cmd, all_envs, path);
	}
	pid_exit_status_caller(pid);
	free_array(all_envs);
}

void	execve_error_manager(char **cmd, char **all_envs, char *path)
{
	ft_putstr_fd(cmd[0], STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	free_array(all_envs);
	free(path);
	free(cmd);
	clear_all_to_exit_smoothly();
	exit(exit_status_holder(127, true));
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
	{
		fork_and_execve(cmd, path);
		if (exit_status_holder(0, false) == 0)
			free(path);
	}
	return (exit_status);
}
