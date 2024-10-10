/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   38.builtin_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/09 15:04:36 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_multiple_args(t_token_list *args, void (*func)(char *))
{
	while (args)
	{
		func(args->lexeme);
		args = args->next;
	}
}

void	builtins_manager(t_token_list *lst)
{
	static bool		arg_option;
	t_token_list	*cmd;

	cmd = lst;
	arg_option = false;
	while (cmd)
	{
		if (cmd->lexeme && ft_strcmp(cmd->lexeme, "echo") == 0)
			builtins_runner_echo(cmd, arg_option);
		else if (cmd->lexeme && ft_strcmp(cmd->lexeme, "cd") == 0)
			builtins_runner_cd(cmd);
		else if (cmd->lexeme && ft_strcmp(cmd->lexeme, "pwd") == 0)
			builtins_runner_pwd(cmd);
		cmd = cmd->next;
	}
}

void	builtins_with_possible_args_manager(t_token_list *lst)
{
	t_token_list    *cmd;

	cmd = lst;
	if (ft_strcmp(cmd->lexeme, "export") == 0)
	{
		if (cmd->next && (cmd->next->type == WORD || cmd->next->type == SINGLE_QUOTES || cmd->next->type == DOUBLE_QUOTES))
			execute_multiple_args(cmd->next, builtins_runner_export);
		else
			builtins_runner_export(NULL);
	}
	else if (ft_strcmp(cmd->lexeme, "unset") == 0
		&& cmd->next && cmd->next->type == WORD)
		execute_multiple_args(cmd->next, builtins_runner_unset);
	else if (ft_strcmp(cmd->lexeme, "env") == 0)
		builtins_runner_env();
	else if (ft_strcmp(cmd->lexeme, "exit") == 0)
	{
		builtins_runner_exit(cmd);
	}
}
