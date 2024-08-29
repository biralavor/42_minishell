/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/29 16:14:41 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expansion_manager(t_token_list *cmd)
{
	t_token_list	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (expansion_detector(tmp))
		{
			if (expansion_env_variable_detector(tmp->lexeme))
				tmp->lexeme = expansion_env_variable_runner(tmp->lexeme);
			else if (expansion_question_mark_detector(tmp->lexeme))
				tmp->lexeme = expansion_question_mark(tmp->lexeme);
		}
		tmp = tmp->next;
	}
}
