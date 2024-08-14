/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.builtins_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/14 15:02:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "executor.h"
#include "builtins.h"

/**
 * @TODO: implement arg_detector for export and unset
 */
void	builtins_manager(t_token_list *lst)
{
	t_token_list	*tmp;

	tmp = lst;
	if (builtins_detector(tmp))
	{
		while (tmp)
		{
			if (ft_strncmp(tmp->lexeme, "echo", 4) == 0)
				builtins_runner_echo(tmp);
			else if (ft_strncmp(tmp->lexeme, "cd", 2) == 0)
				builtins_runner_cd(tmp);
			else if (ft_strncmp(tmp->lexeme, "pwd", 3) == 0)
				builtins_runner_pwd(tmp);
			tmp = tmp->next;
		}
	}
	else if (builtins_detector_with_possible_args(tmp))
		builtins_with_possible_args_manager(tmp);
}

bool	builtins_detector(t_token_list *lst)
{
	t_token_list	*tmp;

	tmp = lst;
	while (tmp && tmp->type == WORD)
	{
		if ((ft_strncmp(tmp->lexeme, "echo", 4) == 0)
			|| (ft_strncmp(tmp->lexeme, "cd", 2) == 0)
			|| (ft_strncmp(tmp->lexeme, "pwd", 3) == 0)
			|| (ft_strncmp(tmp->lexeme, "exit", 4) == 0))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

bool	builtins_detector_with_possible_args(t_token_list *lst)
{
	t_token_list	*tmp;

	tmp = lst;
	while (tmp && tmp->type == WORD)
	{
		if (ft_strncmp(tmp->lexeme, "export", 6) == 0)
			return (true);
		else if (ft_strncmp(tmp->lexeme, "unset", 5) == 0)
			return (true);
		else if (ft_strncmp(tmp->lexeme, "env", 3) == 0)
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
	env_vars = env_holder(NULL, false);
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
