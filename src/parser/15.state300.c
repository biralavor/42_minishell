/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.state300.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:13:10 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/09 11:09:44 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_valid(int type)
{
	if (type == WORD || type == SUBSHELL || type == DOUBLE_QUOTES
		|| type == SINGLE_QUOTES)
		return (true);
	return (false);
}

int	state_300(t_token_list *lst, int syntax_state)
{
	if (lst->next && is_valid(lst->next->type))
		syntax_state = 300;
	else
	{
		error_manager_parser(UNEXPECTED_TOKEN, lst);
		syntax_state = 301;
	}
	return (syntax_state);
}
