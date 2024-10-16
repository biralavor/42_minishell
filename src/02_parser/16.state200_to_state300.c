/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16.state200_to_state300.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/10 22:08:54 by umeneses         ###   ########.fr       */
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

int	state_200(t_token_list *lst, int syntax_state)
{
	if (lst->next && lst->prev
		&& ((is_valid(lst->next->type) || is_redirect(lst->next->type))
			&& (is_valid(lst->prev->type))))
		syntax_state = 200;
	else
	{
		syntax_state = 201;
		error_manager_parser(UNEXPECTED_TOKEN, lst, syntax_state);
		exit_status_holder(2, true);
	}
	return (syntax_state);
}

int	state_300(t_token_list *lst, int syntax_state)
{
	if (lst->next && is_valid(lst->next->type))
		syntax_state = 300;
	else
	{
		syntax_state = 301;
		error_manager_parser(UNEXPECTED_TOKEN, lst, syntax_state);
		exit_status_holder(2, true);
	}
	return (syntax_state);
}
