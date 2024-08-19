/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.builtins_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 10:51:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_manager(t_token_list *lst)
{
	t_token_list	*cmd;
	static bool		arg_detector;

	cmd = lst;
	arg_detector = false;
	while (cmd)
	{
		if (ft_strncmp(cmd->lexeme, "echo", 4) == 0)
			builtins_runner_echo(cmd);
		else if (ft_strncmp(cmd->lexeme, "cd", 2) == 0)
			builtins_runner_cd(cmd);
		// else if (ft_strncmp(cmd[idx], "pwd", 3) == 0)
		// 	builtins_runner_pwd(tmp);
		if (NULL == cmd)
				break ;
		cmd = cmd->next;
	}

	// else if (builtins_detector_with_possible_args(cmd))
	// 	builtins_with_possible_args_manager(cmd);
}

bool	builtins_detector(t_token_list *cmd)
{
	// int	idx;

	// idx = 0;
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

bool	builtins_detector_with_possible_args(t_token_list *lst)
{
	t_token_list	*tmp;

	tmp = lst;
	while (tmp && tmp->type == WORD)
	{
		if ((ft_strncmp(tmp->lexeme, "export", 6) == 0)
			|| (ft_strncmp(tmp->lexeme, "unset", 5) == 0)
			|| (ft_strncmp(tmp->lexeme, "env", 3) == 0))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	builtins_with_possible_args_manager(t_token_list *lst)
{
	t_token_list	*tmp;
	t_env_entry		*env_vars;

	tmp = lst;
	env_vars = env_holder(NULL, false, false);
	while (tmp)
	{
		if (ft_strncmp(tmp->lexeme, "export", 6) == 0)
		{
			if (tmp->next && tmp->next->type == WORD)
				builtins_runner_export(env_vars, tmp->next->lexeme);
			else
				builtins_runner_export(env_vars, NULL);
		}
		else if (ft_strncmp(tmp->lexeme, "unset", 5) == 0)
		{
			if (tmp->next && tmp->next->type == WORD)
				builtins_runner_unset(env_vars, tmp->next->lexeme);
		}
		else if (ft_strncmp(tmp->lexeme, "env", 3) == 0)
			builtins_runner_env(env_vars);
		tmp = tmp->next;
	}
}
