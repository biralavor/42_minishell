/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32.execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:43:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/27 11:24:32 by tmalheir         ###   ########.fr       */
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
	if (pid == 0)
	{
		// check fork
		// check signals
		execve(path, cmd, all_envs);
	}
	// free_array(cmd);
	free_array(all_envs);
	waitpid(pid, &exit_status, 0);
	exit_status = exit_status_holder(exit_status);
	return (exit_status);
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
		return (cmd_name);
	return (NULL);
}

int	command_manager(char **cmd)
{
	int		exit_status;
	char	*path;


	path = NULL;
	path = lookup_cmd_path(cmd[0]);
	if (!path)
	{
		ft_printf("%s: command not found\n", cmd[0]);
		exit_status = 127;
	}
	else
	{
		exit_status = fork_and_execve(cmd, path);
		free(path);
	}
	return (exit_status);
}

int	execute(t_tree *tree)
{
	int		exit_status;
	char	**cmd;

	exit_status = 0; // Retirar após ajustar as funções dos builtins.
	cmd = convert_tokens_to_array(tree->command);
	ft_array_printer(cmd);
	if (builtins_detector(tree->command))
		builtins_manager(tree->command);
	else if (builtins_detector_with_possible_args(tree->command))
		builtins_with_possible_args_manager(tree->command);
	else
		exit_status = command_manager(cmd);
	// verify if !cmd[0]
	// verify exit_status_holder()
	// verify SIGINT
	free_array(cmd);
	return (exit_status);
}

int	tree_execution(t_tree *tree)
{
	int	exit_status;

	exit_status = 2;
	if (!tree)
		return (exit_status);
	else if (tree->type == OR)
		exit_status = manage_or(tree);
	if (tree->type == AND)
		exit_status = manage_and(tree);
/*
	else if (tree->type == PIPE)
		manage_pipe(tree);
	else if (tree->type == REDIR_IN || tree->type == REDIR_HDOC
		|| tree->type == REDIR_OUT || tree->type == REDIR_OUTAPP)
		manage_redir(tree);
	else if (tree->type == SUBSHELL)
		manage_subshell(tree);
*/
	else
		exit_status = execute(tree);
	return (exit_status);
}
