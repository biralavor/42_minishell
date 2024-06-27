/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_initial_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:45:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/26 13:37:25 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	check_initial_errors(char *str)
{
	if ((check_double_quotes(str)) || (check_single_quotes(str))
		|| (check_single_ampersand(str)))
	{
		ft_printf("Syntax error");
		return (1);
	}
	else
		return (0);
}

int	check_double_quotes(char *str)
{
	int		idx;
	int		inside_quotes;

	idx = 0;
	inside_quotes = 0;
	while (str[idx])
	{
		if (str[idx] == '"')
		{
			if (inside_quotes == 0)
				inside_quotes = 1;
			else
				inside_quotes = 0;
		}
		idx++;
	}
	return (inside_quotes);
}

int	check_single_quotes(char *str)
{
	int	idx;
	int	inside_quotes;

	idx = 0;
	inside_quotes = 0;
	while (str[idx])
	{
		if (str[idx] == '\'')
		{
			if (inside_quotes == 0)
				inside_quotes = 1;
			else
				inside_quotes = 0;
		}
		idx++;
	}
	return (inside_quotes);
}

int	check_single_ampersand(char *str)
{
	int	idx;
	int	prev_is_ampersand;

	idx = 0;
	prev_is_ampersand = 0;
	while (str[idx])
	{
		if (str[idx] == '&')
		{
			if (prev_is_ampersand == 0)
				prev_is_ampersand = 1;
			else
				prev_is_ampersand = 0;
		}
		idx++;
	}
	return (prev_is_ampersand);
}
