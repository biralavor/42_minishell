/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14.state200.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/16 09:46:56 by umeneses         ###   ########.fr       */
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
