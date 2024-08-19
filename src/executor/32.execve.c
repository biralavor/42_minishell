/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32.execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:43:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 16:57:43 by umeneses         ###   ########.fr       */
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
	free(path);
	// exit (status == -1)
	// close pid
}

char	*lookup_cmd_path(char *cmd_name)
{
	int			idx;
	char		**all_paths;
	char		*to_execute;
	t_env_entry	*env_path;

	idx = 0;
	to_execute = NULL;
	env_path = lookup_table(env_holder(NULL, false, false), "PATH");
	all_paths = ft_split(env_path->value, ':');
	if (access(cmd_name, F_OK) == 0 || !all_paths)
		{
			free_array(all_paths);
			ft_printf("........executing varriable 'cmd_name': %s\n", to_execute);
			return (ft_strdup(cmd_name));
		}
	while (all_paths[idx])
	{
		all_paths[idx] = ft_strjoin(all_paths[idx], "/");
		to_execute = ft_strjoin(all_paths[idx], ft_strdup(cmd_name));
		if (access(to_execute, F_OK) == 0)
		{
			free_array(all_paths);
			ft_printf("........executing varriable 'to_execute': %s\n", to_execute);
			return (to_execute);
		}
		free(to_execute);
		to_execute = NULL;
		idx++;
	}
	free_array(all_paths);
	return (ft_strdup(cmd_name));
}

/**
 * TODO: implementar built-ins
 */
void	execute(t_tree *tree)
{
	char	*path;
	char	**cmd;

	path = NULL;
	cmd = convert_tokens_to_array(tree->command);
	ft_array_printer(cmd);
	if(!cmd)
		return ;
	if (builtins_detector(tree->command))
		builtins_manager(tree->command);
	else if (builtins_detector_with_possible_args(tree->command))
		builtins_with_possible_args_manager(tree->command);
	else if (cmd[0])
	{
		path = lookup_cmd_path(cmd[0]);
		fork_and_execve(cmd, path);
		// free(path);
	}
	// verify if !cmd[0]
	
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
