/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.builtins_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 15:35:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	builtins_detector(t_token_list *cmd)
{
	while (cmd)
	{
		if ((ft_strncmp(cmd->lexeme, "echo", 4) == 0)
			|| (ft_strncmp(cmd->lexeme, "cd", 2) == 0)
			|| (ft_strncmp(cmd->lexeme, "pwd", 3) == 0)
			|| (ft_strncmp(cmd->lexeme, "exit", 4) == 0))
			return (true);
		cmd = cmd->next;
	}
	return (false);
}

void	builtins_manager(t_token_list *lst)
{
	t_token_list	*cmd;
	static bool		arg_option;

	cmd = lst;
	arg_option = false;
	while (cmd)
	{
		if (ft_strncmp(cmd->lexeme, "echo", 4) == 0)
			builtins_runner_echo(cmd, arg_option);
		else if (ft_strncmp(cmd->lexeme, "cd", 2) == 0)
			builtins_runner_cd(cmd);
		else if (ft_strncmp(cmd->lexeme, "pwd", 3) == 0)
			builtins_runner_pwd(cmd);
		if (NULL == cmd)
			break ;
		cmd = cmd->next;
	}
}

bool	bultins_detector_with_possible_args(t_token_list *lst)
{
	t_token_list	*cmd;

	cmd = lst;
	while (cmd && cmd->type == WORD)
	{
		if ((ft_strncmp(cmd->lexeme, "export", 6) == 0)
			|| (ft_strncmp(cmd->lexeme, "unset", 5) == 0)
			|| (ft_strncmp(cmd->lexeme, "env", 3) == 0))
			return (true);
		cmd = cmd->next;
	}
	return (false);
}

void	builtins_with_possible_args_manager(t_token_list *lst)
{
	t_token_list	*cmd;
	t_env_entry		*env_vars;

	cmd = lst;
	env_vars = env_holder(NULL, false, false);
	while (cmd)
	{
		if (ft_strncmp(cmd->lexeme, "export", 6) == 0)
		{
			if (cmd->next && cmd->next->type == WORD)
				builtins_runner_export(env_vars, cmd->next->lexeme);
			else
				builtins_runner_export(env_vars, NULL);
		}
		else if (ft_strncmp(cmd->lexeme, "unset", 5) == 0)
		{
			if (cmd->next && cmd->next->type == WORD)
				builtins_runner_unset(env_vars, cmd->next->lexeme);
		}
		else if (ft_strncmp(cmd->lexeme, "env", 3) == 0)
			builtins_runner_env(env_vars);
		cmd = cmd->next;
	}
}
