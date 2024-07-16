/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/16 17:06:09 by umeneses         ###   ########.fr       */
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
			if (ft_strncmp(temp->lexeme, "echo", ft_strlen(temp->lexeme)) == 0)
				builtins_runner_echo(temp);
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
		if (ft_strncmp(temp->lexeme, "echo", ft_strlen(temp->lexeme)) == 0)
			return (true);
		if (ft_strncmp(temp->lexeme, "cd", ft_strlen(temp->lexeme)) == 0)
			return (true);
		if (ft_strncmp(temp->lexeme, "pwd", ft_strlen(temp->lexeme)) == 0)
			return (true);
		if (ft_strncmp(temp->lexeme, "export", ft_strlen(temp->lexeme)) == 0)
			return (true);
		if (ft_strncmp(temp->lexeme, "unset", ft_strlen(temp->lexeme)) == 0)
			return (true);
		if (ft_strncmp(temp->lexeme, "env", ft_strlen(temp->lexeme)) == 0)
			return (true);
		if (ft_strncmp(temp->lexeme, "exit", ft_strlen(temp->lexeme)) == 0)
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
