/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:06:03 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/28 14:31:18 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"

bool	check_initial_syntax_errors(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->type == WORD && (((*temp->lexeme) != '"')
				&& (*temp->lexeme) != '\''))
		{
			if (!(check_lexeme_errors(temp->lexeme)))
			{
				parser_error();
				break ;
			}
		}
		else if (temp->type == WORD && (((*temp->lexeme) == '"')
				|| (*temp->lexeme) == '\''))
		{
			if (!(check_empty_quotes(temp->lexeme)))
			{
				parser_error();
				break ;
			}
		}
		temp = temp->next;
	}
	return (true);
}

bool	check_first_node_errors(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	if (temp->type == PIPE || temp->type == OR || temp->type == AND
		|| temp->type == CLOSE_PARENTHESIS)
		return (false);
	return (true);
}

bool	check_lexeme_errors(char *str)
{
	int		idx;
	bool	error_free;

	idx = 0;
	error_free = true;
	while (str[idx])
	{
		if (str[idx] == '&')
			error_free = check_double_ampersand(str);
		else if (str[idx] == ';')
			error_free = check_semicolon(str);
		idx++;
	}
	return (error_free);
}
