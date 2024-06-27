/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_initial_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:45:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/27 14:39:40 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

bool	check_initial_errors(char *str)
{
	if (!(check_closed_double_quotes(str))
		|| !(check_closed_single_quotes(str))
		|| !(check_double_ampersand(str)) || !(check_semicolon(str)))
		return (false);
	else
		return (true);
}

bool	check_closed_double_quotes(char *str)
{
	int		idx;
	bool	inside_quotes;

	idx = 0;
	inside_quotes = true;
	while (str[idx])
	{
		if (str[idx] == '"')
		{
			if (inside_quotes == true)
				inside_quotes = false;
			else
				inside_quotes = true;
		}
		idx++;
	}
	return (inside_quotes);
}

bool	check_closed_single_quotes(char *str)
{
	int		idx;
	bool	inside_quotes;

	idx = 0;
	inside_quotes = true;
	while (str[idx])
	{
		if (str[idx] == '\'')
		{
			if (inside_quotes == true)
				inside_quotes = false;
			else
				inside_quotes = true;
		}
		idx++;
	}
	return (inside_quotes);
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
