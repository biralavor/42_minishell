/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.state200.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/12 14:14:32 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	state_200(t_token_list *lst, int syntax_state)
{
	if (lst->next && lst->prev && (lst->next->type == WORD
			|| lst->next->type == SUBSHELL || lst->prev->type == WORD))
		syntax_state = 200;
	else
	{
		error_manager_parser(UNEXPECTED_TOKEN, lst);
		syntax_state = 201;
	}
	return (syntax_state);
}

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
