/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.state100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:20:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/26 09:12:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

bool	check_backlash(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '\\')
			return (false);
		idx++;
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
		if (str[idx] == '\\')
			error_free = check_backlash(str);
		else if (str[idx] == '&')
			error_free = check_double_ampersand(str);
		else if (str[idx] == ';')
			error_free = check_semicolon(str);
		idx++;
	}
	return (error_free);
}

int	state_100(t_token_list *lst, int syntax_state)
{
	syntax_state = 100;
	if (lst->type == WORD)
	{
		if (!check_lexeme_errors(lst->lexeme))
		{
			syntax_state = 101;
			error_manager_parser(SYNTAX_ERROR, lst->lexeme, syntax_state);
			exit_status_holder(2, true);
		}
	}
	return (syntax_state);
}
