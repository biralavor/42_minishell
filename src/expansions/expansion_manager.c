/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/11 15:58:56 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expansion_manager(t_token_list *cmd)
{
	t_token_list	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (expansion_quotes_detector(tmp))
			tmp->lexeme = expansion_quotes_runner(tmp->lexeme);
		if (expansion_tilde_detector(tmp->lexeme))
			tmp->lexeme = expansion_tilde_to_home(tmp->lexeme);
		if (expansion_dollar_sign_detector(tmp))
		{
			if (expansion_env_var_detector(tmp->lexeme))
				tmp->lexeme = expansion_env_var_runner(tmp->lexeme);
			else if (expansion_question_mark_detector(tmp->lexeme))
				tmp->lexeme = expansion_question_mark(tmp->lexeme);
		}
		tmp = tmp->next;
	}
}
