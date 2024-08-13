/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.builtins_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/13 16:12:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "executor.h"
#include "builtins.h"

void	builtins_manager(t_token_list *lst)
{
	t_token_list	*tmp;
	t_env_entry		*env_vars;

	tmp = lst;
	env_vars = env_holder(NULL, false);
	if (builtins_detector(tmp))
	{
		while (tmp)
		{
			if (tmp->type == WORD)
			{
				if (ft_strncmp(tmp->lexeme, "echo", 4) == 0)
					builtins_runner_echo(tmp);
				if (ft_strncmp(tmp->lexeme, "cd", 2) == 0)
					builtins_runner_cd(tmp);
				if (ft_strncmp(tmp->lexeme, "pwd", 3) == 0)
					builtins_runner_pwd(tmp);
				if (ft_strncmp(tmp->lexeme, "export", 6) == 0)
					builtins_runner_export(env_vars, tmp->next->lexeme);
			}
			tmp = tmp->next;
		}
	}
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
			|| (ft_strncmp(tmp->lexeme, "export", 6) == 0)
			|| (ft_strncmp(tmp->lexeme, "unset", 5) == 0)
			|| (ft_strncmp(tmp->lexeme, "env", 3) == 0)
			|| (ft_strncmp(tmp->lexeme, "exit", 4) == 0))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
