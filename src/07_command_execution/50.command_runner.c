/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   50.command_runner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:51:30 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/07 21:11:38 by umeneses         ###   ########.fr       */
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
		signal(SIGQUIT, SIG_DFL);
		exit_status_holder(execve(path, cmd, all_envs), true);
		if (exit_status_holder(0, false) != 0)
			execve_error_manager(cmd, all_envs, path);
	}
	pid_exit_status_caller(pid);
	child_process_is_running(false, false);
	free_array(all_envs);
	free(path);
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
