/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.check_initial_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:45:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/30 14:18:08 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_closed_quotes(char *str)
{
	int		idx;
	int		quote_idx;
	char	quote_type;

	idx = 0;
	quote_idx = 0;
	quote_type = '\0';
	while (str[idx] != '\0')
	{
		if (quote_type == '\0' && str[idx]
			&& (str[idx] == '"' || str[idx] == '\''))
		{
			quote_type = str[idx];
			quote_idx++;
			idx++;
		}
		if (quote_type == str[idx])
			quote_idx++;
		if (str[idx])
			idx++;
	}
	return (quote_idx % 2 == 0);
}

int	between_quotes(int idx, char *str)
{
	if (str[idx] == '"')
	{
		idx++;
		while (str[idx] != '"')
			idx++;
	}
	else if (str[idx] == '\'')
	{
		idx++;
		while (str[idx] != '\'')
			idx++;
	}
	return (idx);
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

bool	match_parenthesis(int open, int close)
{
	if (open != close)
		return (false);
	else
		return (true);
}
