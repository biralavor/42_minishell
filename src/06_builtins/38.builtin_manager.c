/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   36.builtins_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/13 09:15:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_manager(t_token_list *lst)
{
	static bool		arg_option;
	t_token_list	*cmd;

	cmd = lst;
	arg_option = false;
	while (cmd)
	{
		if (ft_strncmp(cmd->lexeme, "echo", ft_strlen(cmd->lexeme)) == 0)
			builtins_runner_echo(cmd, arg_option);
		else if (ft_strncmp(cmd->lexeme, "cd", ft_strlen(cmd->lexeme)) == 0)
			builtins_runner_cd(cmd);
		else if (ft_strncmp(cmd->lexeme, "pwd", ft_strlen(cmd->lexeme)) == 0)
			builtins_runner_pwd(cmd);
		cmd = cmd->next;
	}
}

void	builtins_with_possible_args_manager(t_token_list *lst)
{
	t_token_list	*cmd;

	cmd = lst;
	while (cmd)
	{
		if (ft_strncmp(cmd->lexeme, "export", ft_strlen(cmd->lexeme)) == 0)
		{
			if (cmd->next && cmd->next->type == WORD)
				builtins_runner_export(cmd->next->lexeme);
			else
				builtins_runner_export(NULL);
		}
		else if (ft_strncmp(cmd->lexeme, "unset", ft_strlen(cmd->lexeme)) == 0
			&& cmd->next && cmd->next->type == WORD)
			builtins_runner_unset(cmd->next->lexeme);
		else if (ft_strncmp(cmd->lexeme, "env", ft_strlen(cmd->lexeme)) == 0)
			builtins_runner_env();
		else if (ft_strncmp(cmd->lexeme, "exit", ft_strlen(cmd->lexeme)) == 0)
		{
			builtins_runner_exit(cmd);
			break ;
		}
		cmd = cmd->next;
	}
}