/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.check_initial_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:45:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/08 20:13:38 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "error_manager.h"

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
	bool	flag;

	idx = 0;
	flag = true;
	while (str[idx])
	{
		if (str[idx] == '"')
		{
			if (flag == true)
				flag = false;
			else
				flag = true;
		}
		idx++;
	}
	return (flag);
}

bool	check_closed_single_quotes(char *str)
{
	int		idx;
	bool	flag;

	idx = 0;
	flag = true;
	while (str[idx])
	{
		if (str[idx] == '\'')
		{
			if (flag == true)
				flag = false;
			else
				flag = true;
		}
		idx++;
	}
	return (flag);
}
