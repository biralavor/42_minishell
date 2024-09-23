/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.check_initial_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:45:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/17 17:12:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_initial_errors(char *str)
{
	if (!(check_closed_quotes(str))
		|| !(check_closed_parenthesis(str)))
		return (false);
	else
		return (true);
}

bool	check_closed_quotes(char *str)
{
	int		idx;
	int		quote_idx;
	char	quote_type;

	idx = 0;
	quote_idx = 0;
	quote_type = '\0';
	while (str[idx])
	{
		if (quote_type == '\0' && (str[idx] == '"' || str[idx] == '\''))
		{
			quote_type = str[idx];
			quote_idx++;
			idx++;
		}
		if (quote_type == str[idx])
			quote_idx++;
		idx++;
	}
	if (quote_idx % 2 == 0)
		return (true);
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
