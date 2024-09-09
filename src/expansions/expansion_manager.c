/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 16:31:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expansion_manager(t_token_list *cmd)
{
	t_token_list	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (expansion_quotes_detector_at_middle(tmp))
			tmp->lexeme = expansion_quotes_runner_at_middle(tmp->lexeme);
		if (expansion_tilde_detector(tmp->lexeme))
			tmp->lexeme = expansion_tilde_to_home(tmp->lexeme);
		if (expansion_detector_at_start(tmp))
		{
			if (expansion_env_var_detector_at_start(tmp->lexeme[1]))
				tmp->lexeme = expansion_env_var_runner_at_start(tmp->lexeme);
			else if (expansion_question_mark_detector(tmp->lexeme[1])
				&& tmp->lexeme[2] == '\0')
				tmp->lexeme = expansion_question_mark(tmp->lexeme);
		}
		else if (expansion_detector_at_middle(tmp))
		{
			if (expansion_env_var_detector_at_middle(tmp))
				tmp->lexeme = expansion_env_var_runner_at_middle(tmp->lexeme);
		}
		tmp = tmp->next;
	}
}
