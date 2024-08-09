/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 15:00:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "builtins.h"

void	builtins_controller(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	if (builtins_detector(temp))
	{
		while (temp)
		{
			if (temp->type == WORD)
			{
				if (ft_strncmp(temp->lexeme, "echo", 4) == 0)
					builtins_runner_echo(temp);
				if (ft_strncmp(temp->lexeme, "cd", 2) == 0)
					builtins_runner_cd(temp);
				if (ft_strncmp(temp->lexeme, "pwd", 3) == 0)
					builtins_runner_pwd(temp);
				if (ft_strncmp(temp->lexeme, "export", 6) == 0)
					builtins_runner_export(temp);
			}
			temp = temp->next;
		}
	}
}

bool	builtins_detector(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp && temp->type == WORD)
	{
		if ((ft_strncmp(temp->lexeme, "echo", 4) == 0)
			|| (ft_strncmp(temp->lexeme, "cd", 2) == 0)
			|| (ft_strncmp(temp->lexeme, "pwd", 3) == 0)
			|| (ft_strncmp(temp->lexeme, "export", 6) == 0)
			|| (ft_strncmp(temp->lexeme, "unset", 5) == 0)
			|| (ft_strncmp(temp->lexeme, "env", 3) == 0)
			|| (ft_strncmp(temp->lexeme, "exit", 4) == 0))
			return (true);
		temp = temp->next;
	}
	return (false);
}
