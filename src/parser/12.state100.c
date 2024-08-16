/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12.state100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:20:31 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/16 09:46:48 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	state_100(t_token_list *lst, int syntax_state)
{
	syntax_state = 100;
	if (lst->type == WORD)
	{
		if (!check_lexeme_errors(lst->lexeme))
		{
			error_manager_parser(SYNTAX_ERROR, lst);
			syntax_state = 101;
		}
	}
	return (syntax_state);
}

bool	check_lexeme_errors(char *str)
{
	int		idx;
	bool	error_free;

	idx = 0;
	error_free = true;
	while (str[idx])
	{
		if (str[idx] == '\\')
			error_free = check_backlash(str);
		else if (str[idx] == '&')
			error_free = check_double_ampersand(str);
		else if (str[idx] == ';')
			error_free = check_semicolon(str);
		idx++;
	}
	return (error_free);
}
