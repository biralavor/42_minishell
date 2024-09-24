/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06.check_initial_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:45:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/24 09:18:43 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	check_closed_quotes(char *str)
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
	if (quote_idx % 2 == 0)
		return (true);
	return (false);
}

bool	inside_quotes_detector(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (idx > 0 && str[idx - 1] && str[idx - 1] == ' '
			&& (str[idx] == '"' || str[idx] == '\''))
			return (false);
		else if (idx > 0 && str[idx - 1] && str[idx - 1] == '='
			&& (str[idx] == '"' || str[idx] == '\''))
			return (false);
		else if (idx > 0 && str[idx - 1] && str[idx - 1] == '\''
			&& str[idx] == '$')
			return (false);
		else if (idx > 0 && (str[idx] == '"' || str[idx] == '\'')
			&& str[idx - 1] != ' ' && str[idx + 1] != '$'
			&& str[idx + 1] != '\0')
			return (true);
		idx++;
	}
	return (false);
}

char	*update_str_if_inside_quotes(char *str)
{
	int		idx;
	char	quote_type;

	idx = 1;
	quote_type = '\0';
	while (str[idx])
	{
		if (quote_type == '\0' && str[idx - 1] && str[idx - 1] != ' '
			&& (str[idx] == '"' || str[idx] == '\''))
		{
			quote_type = str[idx];
			ft_memmove(&str[idx], &str[idx + 1], ft_strlen(&str[idx + 1]) + 1);
		}
		if (quote_type == str[idx])
		{
			quote_type = '\0';
			ft_memmove(&str[idx], &str[idx + 1], ft_strlen(&str[idx + 1]) + 1);
		}
		idx++;
	}
	if (inside_quotes_detector(str) && check_closed_quotes(str))
		update_str_if_inside_quotes(str);
	return (str);
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
