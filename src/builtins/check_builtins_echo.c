/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins_echo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 14:49:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "builtins.h"

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
			if (builtins_check_cmd_arg(lst, 'n'))
				temp = temp->next->next;
			while (temp->type == WORD)
			{
				ft_putstr_fd(temp->lexeme, STDOUT_FILENO);
				if (NULL == temp->next)
					break ;
				else
					ft_putstr_fd(" ", STDOUT_FILENO);
				temp = temp->next;
			}
			if (!builtins_check_cmd_arg(lst, 'n'))
				write(1, "\n", 1);
		}
	}
}

bool	builtins_check_cmd_arg(t_token_list *lst, char arg)
{
	t_token_list	*temp;

	temp = lst;
	if (temp->next->lexeme[0] == '-')
	{
		if (temp->next->lexeme[1] == arg)
			return (true);
	}
	return (false);
}
