/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13.lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/09 16:51:47 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_next_char(char curr, char next)
{
	if (curr == next)
		return (0);
	else
		return (1);
}

int	is_blank(char c)
{
	if ((c == ' ') || (c == '\t') || (c == '\v') || (c == '\n') || (c == '\r'))
		return (1);
	else
		return (0);
}

bool	is_empty(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '(' && str[idx + 1] == ')')
			return (false);
		idx++;
	}
	return (true);
}

int	check_double(char *str, int idx, bool flag)
{
	while (str[idx])
	{
		if (str[idx] == '"' && !flag)
		{
			flag = true;
			idx++;
		}
		if (str[idx] == '"' && flag)
		{
			if (str[idx + 1] && (str[idx + 1] != '(') && (str[idx + 1] != ')')
				&& (str[idx + 1] != '|') && (str[idx + 1] != '&')
				&& (str[idx + 1] != '>') && (str[idx + 1] != '<')
				&& !(is_blank(str[idx + 1])))
				idx++;
			else
				return (idx);
		}
		else
			idx++;
	}
	return (idx);
}

int	check_single(char *str, int idx)
{
	while (str[idx])
	{
		if (str[idx] == '\'')
		{
			if (str[idx + 1] && (str[idx + 1] != '(') && (str[idx + 1] != ')')
				&& (str[idx + 1] != '|') && (str[idx + 1] != '&') && (str[idx + 1] != '>')
				&& (str[idx + 1] != '<') && !(is_blank(str[idx + 1])))
				idx++;
			else
				break ;
		}
		idx++;
	}
	return (idx);
}
