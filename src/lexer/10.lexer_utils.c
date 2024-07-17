/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:12:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/16 16:48:56 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

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

bool	match_parenthesis(int open, int close)
{
	if (open != close)
		return (false);
	else
		return (true);
}
