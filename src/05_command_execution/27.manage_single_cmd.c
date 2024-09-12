/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32.execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:43:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/12 18:37:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fork_and_execve(char **cmd, char *path)
{
	int		exit_status;
	char	**all_envs;
	pid_t	pid;

	all_envs = convert_envs_to_array(env_holder(NULL, false, false));
	pid = fork();
	if (pid == -1)
		return (fork_error());
	if (pid == 0)
	{
		// check signals
		execve(path, cmd, all_envs);
		if (errno == ENOENT)
		{
			ft_putstr_fd(cmd[0], STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit_status_holder(127, true);
			// clear_all_to_exit_smoothly();
		}
		// else // outro tipo de erro
		// {
		// 	ft_printf("%s: %s\n", cmd[0], strerror(errno));
		// }
	}
	free_array(all_envs);
	waitpid(pid, &exit_status, 0);
	return (exit_status_holder(exit_status, true));
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

int	command_manager(char **cmd)
{
	int		exit_status;
	char	*path;

	path = NULL;
	exit_status = 0;
	path = lookup_cmd_path(cmd[0]);
	if (path)
	{
		exit_status = fork_and_execve(cmd, path);
		free(path);
	}
	free_array(cmd);
	return (exit_status);
}

int	manage_single_command(t_tree *tree)
{
	static int	exit_status;
	char		**cmd;

	cmd = NULL;
	expansion_manager(tree->command);
	if (builtins_detector(tree->command))
		builtins_manager(tree->command);
	else if (builtins_detector_with_possible_args(tree->command))
		builtins_with_possible_args_manager(tree->command);
	else
	{
		cmd = convert_tokens_to_array(tree->command);
		if (!cmd)
		{
			exit_status = 1; // trocar por exit_holder
			return (exit_status);
		}
		exit_status = command_manager(cmd); // trocar por exit_holder
	}
	// verify if !cmd[0]
	// verify exit_status_holder()
	// verify SIGINT
	return (exit_status);
}
