/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13.state200.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/04 16:48:34 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

int	state_200(t_token_list *lst, int syntax_state)
{
	if (lst->next && lst->prev && (lst->next->type == WORD
		|| lst->next->type == CLOSE_PARENTHESIS || lst->prev->type == WORD
		|| lst->prev->type == OPEN_PARENTHESIS))
		syntax_state = 200;
	else
	{
		error_manager_parser(UNEXPECTED_TOKEN, lst);
		syntax_state = 201;
	}
	return (syntax_state);
}
