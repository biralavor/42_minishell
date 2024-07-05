/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16.state400.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:15:30 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/05 11:23:52 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

int	state_400(t_token_list *lst, int syntax_state)
{
	int				open;
	int				close;
	t_token_list	*temp;

	open = 0;
	close = 0;
	temp = lst;
	while (temp)
	{
		if (temp->type == OPEN_PARENTHESIS)
		{
			if (temp->next && temp->next->type == CLOSE_PARENTHESIS)
			{
				syntax_state = state_401(temp);
				return (syntax_state);
			}
			open += 1;
		}
		else if (temp->type == CLOSE_PARENTHESIS)
			close += 1;
		temp = temp->next;
	}
	syntax_state = match_parenthesis(open, close, temp);
	return (syntax_state);
}

int	state_401(t_token_list *lst)
{
	error_manager_parser(UNEXPECTED_TOKEN, lst);
	return (801);
}

int	state_402(t_token_list *lst)
{
	error_manager_parser(PARENTHESIS_ERROR, lst);
	return (802);
}

int	match_parenthesis(int open, int close, t_token_list *lst)
{
	int	syntax_state;

	if (open != close)
		syntax_state = state_402(lst);
	else
		syntax_state = 403;
	return (syntax_state);
}
