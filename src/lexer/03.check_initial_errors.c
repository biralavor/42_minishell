/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.check_initial_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:45:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/18 10:12:28 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "error_manager.h"

bool	check_initial_errors(char *str)
{
	if (!(check_closed_double_quotes(str))
		|| !(check_closed_single_quotes(str))
		|| !(check_closed_parenthesis(str)))
		return (false);
	else
		return (true);
}

bool	check_closed_double_quotes(char *str)
{
	int		idx;
	int		double_quote;

	idx = 0;
	double_quote = 0;
	while (str[idx])
	{
		if (str[idx] == '"')
			double_quote += 1;
		idx++;
	}
	if (double_quote % 2 == 0)
		return (true);
	else
		return (false);
}

bool	check_closed_single_quotes(char *str)
{
	int		idx;
	int		single_quote;

	idx = 0;
	single_quote = 0;
	while (str[idx])
	{
		if (str[idx] == '\'')
			single_quote += 1;
		idx++;
	}
	if (single_quote % 2 == 0)
		return (true);
	else
		return (false);
}

bool	check_closed_parenthesis(char *str)
{
	int		idx;
	int		open;
	int		close;

	idx = 0;
	open = 0;
	close = 0;
	while (str[idx])
	{
		if (str[idx] == '"' || str[idx] == '\'')
			idx = between_quotes(idx, str);
		else if (str[idx] == '(')
			idx = between_parenthesis(idx, str);
		else if (str[idx] == '(')
			open += 1;
		else if (str[idx] == ')')
			close += 1;
		idx++;
	}
	if (!match_parenthesis(open, close))
		return (false);
	return (true);
}

int	between_parenthesis(int idx, char *str)
{
	int	end;
	int	count;

	end = -1;
	count = 0;
	while (str[idx])
	{
		if (str[idx] == '(')
			count++;
		else if (str[idx] == ')')
		{
			count--;
			if (count == 0)
			{
				end = idx;
				break ;
			}
		}
		idx++;
	}
	return (end);
}
