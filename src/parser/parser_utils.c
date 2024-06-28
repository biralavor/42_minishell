/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:03:18 by tmalheir          #+#    #+#             */
/*   Updated: 2024/06/28 14:33:20 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"

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

bool	check_empty_quotes(char *str)
{
	int	idx;

	idx = 0;
	if ((str[idx] == '"' && str[idx + 1] == '"')
		|| (str[idx] == '\'' && str[idx + 1] == '\''))
	{
		ft_printf("Command %c not found\n", str[idx]);
		return (false);
	}
	return (true);
}

bool	parser_error(void)
{
	ft_printf("parser error\n");
	return (false);
}
