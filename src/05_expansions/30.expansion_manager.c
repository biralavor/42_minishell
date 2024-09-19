/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30.expansion_manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/19 20:06:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expansion_manager(t_token_list *cmd)
{
	t_token_list	*tmp;

	tmp = cmd;
	while (tmp != NULL)
	{
		if (expansion_tilde_detector(tmp->lexeme))
			tmp->lexeme = expansion_tilde_to_home(tmp->lexeme);
		if (expansion_dollar_sign_detector(tmp))
		{
			if (expansion_question_mark_detector(tmp->lexeme))
				tmp->lexeme = expansion_question_mark(tmp->lexeme);
			tmp->lexeme = expansion_env_var_runner(tmp->lexeme, tmp->type);
			// if (single_quote_detector(tmp->lexeme))
			// 	tmp->lexeme = single_quote_remover(tmp->lexeme);
		}
		tmp = tmp->next;
	}	
}

int	next_char_counter(t_token_list *cmd)
{
	t_token_list	*tmp;
	int				idx;

	tmp = cmd;
	idx = 0;
	while (tmp)
	{
		if (tmp->next_char == '\0')
			break ;
		if (tmp->next_char != ' ')
			idx++;
		tmp = tmp->next;
	}
	return (idx);
}
