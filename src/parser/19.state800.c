/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19.state800.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:15:30 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/04 15:10:22 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

int	state_800(t_token_list *lst, int syntax_state)
{
	int				open_parenthesis;
	int				close_parenthesis;
	t_token_list	*temp;

	open_parenthesis = 0;
	close_parenthesis = 0;
	temp = lst;
	while (temp)
	{
		if (temp->type == OPEN_PARENTHESIS)
		{
			if (temp->next && temp->next->type == CLOSE_PARENTHESIS)
			{
				syntax_state = state_801(temp);
				return (syntax_state);
			}
			open_parenthesis += 1;
		}
		else if (temp->type == CLOSE_PARENTHESIS)
			close_parenthesis += 1;
		temp = temp->next;
	}
	matched_parenthesis(open_parenthesis, close_parenthesis, temp);
	return (syntax_state);
}

int	state_801(t_token_list *lst)
{
	error_manager_parser(UNEXPECTED_TOKEN, lst);
	return (801);
}

int	state_802(t_token_list *lst)
{
	error_manager_parser(PARENTHESIS_ERROR, lst);
	return (802);
}

int	matched_parenthesis(int open_par, int close_par, t_token_list *lst)
{
	int	syntax_state;

	if (open_par != close_par)
		syntax_state = state_802(lst);
	else
		syntax_state = 803;
	return (syntax_state);
}
