/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32.execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:43:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/27 11:48:24 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_and_execve(char **cmd, char *path)
{
	char	**all_envs;
	pid_t	pid;

	all_envs = convert_envs_to_array(env_holder(NULL, false, false));
	pid = fork();
	if (pid == -1)
	{
		// pid error
	}
	if (pid == 0)
	{
		// check fork
		// check signals
		execve(path, cmd, all_envs);
	}
	// treat erros (path)
	// free_array(cmd);
	free_array(all_envs);
	// exit (status == -1)
	// close pid
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

void	command_manager(char **cmd)
{
	char	*path;

	path = NULL;
	path = lookup_cmd_path(cmd[0]);
	if (!path)
		ft_printf("%s: command not found\n", cmd[0]);
	else
	{
		fork_and_execve(cmd, path);
		free(path);
	}
}

void	execute(t_tree *tree)
{
	char	**cmd;

	cmd = convert_tokens_to_array(tree->command);
	ft_array_printer(cmd);
	if (!cmd)
		return ;
	if (builtins_detector(tree->command))
		builtins_manager(tree->command);
	else if (builtins_detector_with_possible_args(tree->command))
		builtins_with_possible_args_manager(tree->command);
	else if (cmd)
		command_manager(cmd);
	// verify if !cmd[0]
	// verify exit_status_holder()
	// verify SIGINT
	free_array(cmd);
}

void	tree_execution(t_tree *tree)
{
	if (tree->left)
		tree_execution(tree->left);
	else if (tree->right)
		tree_execution(tree->right);
	else if (tree->command && tree->command->lexeme)
	{
		execute(tree);
	}
}
