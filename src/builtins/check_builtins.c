/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 12:45:58 by umeneses         ###   ########.fr       */
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

void	builtins_runner_echo(t_token_list *lst)
{
	t_token_list	*temp;
	int				lex_cmd_len;
	char			*lex_cmd;

	temp = lst;
	while (temp && temp->type == WORD && NULL != temp->next)
	{
		lex_cmd = temp->lexeme;
		lex_cmd_len = ft_strlen(temp->lexeme);
		if (ft_strncmp(lex_cmd, "echo", lex_cmd_len) == 0)
		{
			while (temp->next->type == WORD)
			{
				temp = temp->next;
				ft_putstr_fd(temp->lexeme, STDOUT_FILENO);
				if (NULL == temp->next)
					break ;
				else
					ft_putstr_fd(" ", STDOUT_FILENO);
			}
		}
	}
}

void	builtins_runner_pwd(t_token_list *lst)
{
	t_token_list	*temp;
	int				lex_cmd_len;
	char			*lex_cmd;
	char			*actual_path;

	temp = lst;
	actual_path = NULL;
	if (temp && temp->type == WORD)
	{
		lex_cmd = temp->lexeme;
		lex_cmd_len = ft_strlen(temp->lexeme);
		if (ft_strncmp(lex_cmd, "pwd", lex_cmd_len) == 0)
		{
			actual_path = getcwd(actual_path, 100);
			ft_putstr_fd(actual_path, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
		}
	}
}
