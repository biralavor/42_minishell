/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.state100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:20:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/04 16:40:18 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

int	state_100(t_token_list *lst, int syntax_state)
{
	if (lst->type == WORD && (((*lst->lexeme) != '"')
			&& (*lst->lexeme) != '\''))
	{
		if (!(check_lexeme_errors(lst->lexeme)))
		{
			error_manager_parser(SYNTAX_ERROR, lst);
			syntax_state = 101;
		}
	}
	else if (lst->type == WORD && (((*lst->lexeme) == '"')
			|| (*lst->lexeme) == '\''))
	{
		if (!(check_empty_quotes(lst->lexeme)))
		{
			error_manager_parser(SYNTAX_ERROR, lst);
			syntax_state = 101;
		}
	}
	syntax_state = 100;
	return (syntax_state);
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

bool	check_double_ampersand(char *str)
{
	int		idx;
	bool	prev_is_ampersand;

	idx = 0;
	prev_is_ampersand = true;
	while (str[idx])
	{
		if (str[idx] == '&')
		{
			if (prev_is_ampersand == true)
				prev_is_ampersand = false;
			else
				prev_is_ampersand = true;
		}
		idx++;
	}
	return (prev_is_ampersand);
}

bool	check_semicolon(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == ';')
			return (false);
		idx++;
	}
	return (true);
}

bool	check_empty_quotes(char *str)
{
	int	idx;

	idx = 0;
	if ((str[idx] == '"' && str[idx + 1] == '"')
		|| (str[idx] == '\'' && str[idx + 1] == '\''))
		return (false);
	return (true);
}
