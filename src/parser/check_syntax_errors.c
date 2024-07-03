/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:06:03 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/02 14:39:55 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"

bool	check_first_and_last_node(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	if (temp->type == PIPE || temp->type == OR || temp->type == AND
		|| temp->type == CLOSE_PARENTHESIS)
		return (false);
	while (temp->next)
		temp = temp->next;
	if (temp->type == PIPE || temp->type == OR || temp->type == AND
		|| temp->type == OPEN_PARENTHESIS)
		return (false);
	return (true);
}

bool	check_lexeme(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->type == WORD && (((*temp->lexeme) != '"')
				&& (*temp->lexeme) != '\''))
		{
			if (!(check_lexeme_errors(temp->lexeme)))
				return (false);
		}
		temp = temp->next;
	}
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

bool	check_quotes(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->type == WORD && (((*temp->lexeme) == '"')
				|| (*temp->lexeme) == '\''))
		{
			if (!(check_empty_quotes(temp->lexeme)))
				return (false);
		}
		temp = temp->next;
	}
	return (true);
}

bool	check_closed_parenthesis(t_token_list *lst)
{
	bool			close_parenthesis;
	t_token_list	*temp;

	close_parenthesis = true;
	temp = lst;
	while (temp)
	{
		if (temp->type == OPEN_PARENTHESIS)
			close_parenthesis = false;
		if (temp->type == CLOSE_PARENTHESIS)
			close_parenthesis = true;
		temp = temp->next;
	}
	return (close_parenthesis);
}
