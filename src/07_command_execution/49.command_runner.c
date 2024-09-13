/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   49.command_runner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:51:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/13 20:40:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fork_and_execve(char **cmd, char *path)
{
	// int		exit_status;
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
		return (fork_error());
	if (pid == 0)
	{
		// env_holder(NULL, false, true);
		// rl_clear_history();
		// check signals
		// child_process_is_running(true, true)
		exit_status_holder(execve(path, cmd, all_envs), true);
		if (exit_status_holder(0, false) != 0)
		{
			ft_putstr_fd(cmd[0], STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			free_array(all_envs);
			free(cmd);
			free(path);
			clear_all_to_exit_smoothly();
			exit(exit_status_holder(127, true));
		}
	}
	else
		free(path);
	pid_exit_status_caller(pid);
	if (!child_process_is_running(false, true))
		free_array(all_envs);
	return (exit_status_holder(0, false));
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
		exit_status = fork_and_execve(cmd, path);
		// free(path);
	}
	// if (child_process_is_running(false, true))
	// 	free_array(cmd);
	return (exit_status);
}
