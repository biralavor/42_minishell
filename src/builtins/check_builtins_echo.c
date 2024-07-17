/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins_echo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/17 12:51:08 by umeneses         ###   ########.fr       */
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
			while (temp->next->type == WORD)
			{
				temp = temp->next;
				ft_putstr_fd(temp->lexeme, STDOUT_FILENO);
				if (NULL == temp->next)
					break ;
				else
					ft_putstr_fd(" ", STDOUT_FILENO);
			}
			write(1, "\n", 1);
		}
	}
}
