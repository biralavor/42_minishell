/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.check_initial_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:45:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/16 13:07:30 by tmalheir         ###   ########.fr       */
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
	bool	flag;
	int		double_quote;

	idx = 0;
	double_quote = 0;
	flag = true;
	while (str[idx])
	{
		if (str[idx] == '"')
		{
			if ((str[idx + 1]) && (str[idx - 1])
				&& (str[idx + 1] == '"') && (str[idx - 1] == '"'))
			{
				flag = false;
				return (flag);
			}
			double_quote += 1;
		}
		idx++;
	}
	if (double_quote % 2 == 0)
		flag = true;
	return (flag);
}

bool	check_closed_single_quotes(char *str)
{
	int		idx;
	bool	flag;
	int		double_quote;

	idx = 0;
	double_quote = 0;
	flag = true;
	while (str[idx])
	{
		if (str[idx] == '\'')
		{
			if ((str[idx + 1]) && (str[idx - 1])
				&& (str[idx + 1] == '\'') && (str[idx - 1] == '\''))
			{
				flag = false;
				return (flag);
			}
			double_quote += 1;
		}
		idx++;
	}
	if (double_quote % 2 == 0)
		flag = true;
	return (flag);
}

bool	check_closed_parenthesis(char *str)
{
	int		idx;
	bool	flag;
	int		open;
	int		close;

	idx = 0;
	open = 0;
	close = 0;
	flag = true;
	while (str[idx])
	{
		if (str[idx] == '(' && str[idx + 1] && str[idx + 1] == ')')
			return (false);
		else if (str[idx] == '(')
			open += 1;
		else if (str[idx] == ')')
			close += 1;
		idx++;
	}
	flag = match_parenthesis(open, close);
	return (flag);
}

bool	match_parenthesis(int open, int close)
{
	if (open != close)
		return (false);
	else
		return (true);
}
