/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_initial_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:45:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/28 12:24:35 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

bool	check_initial_errors(char *str)
{
	if (!(check_closed_double_quotes(str))
		|| !(check_closed_single_quotes(str)))
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
