/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 10:08:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expansion_manager(t_token_list *cmd)
{
	t_token_list	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (expansion_detector_at_start(tmp))
		{
			if (expansion_env_var_detector(tmp->lexeme[1]))
				tmp->lexeme = expansion_env_var_runner_at_start(tmp->lexeme);
			else if (expansion_question_mark_detector(tmp->lexeme[1])
				&& tmp->lexeme[2] == '\0')
				tmp->lexeme = expansion_question_mark(tmp->lexeme);
		}
		else if (expansion_detector_at_middle(tmp))
		{
			
		}
		tmp = tmp->next;
	}
}
