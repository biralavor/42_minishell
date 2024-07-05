/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.state300.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:13:10 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/05 11:39:58 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

int	state_300(t_token_list *lst, int syntax_state)
{
	if (lst->next && lst->next->type == WORD)
		syntax_state = 300;
	else
	{
		error_manager_parser(UNEXPECTED_TOKEN, lst);
		syntax_state = 301;
	}
	return (syntax_state);
}
