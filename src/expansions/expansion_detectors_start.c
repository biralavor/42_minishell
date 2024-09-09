/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_detectors_start.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 10:17:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expansion_detector_at_start(t_token_list *cmd)
{
	if (cmd->type == WORD && cmd->lexeme[0] == '$')
		return (true);
	return (false);
}

bool	expansion_env_var_detector_at_start(char lexeme_char_pos)
{
	if (ft_isalpha(lexeme_char_pos) || lexeme_char_pos == '_')
		return (true);
	return (false);
}

bool	expansion_question_mark_detector(char lexeme_char_pos)
{
	if (lexeme_char_pos == '?')
		return (true);
	return (false);
}

// bool	expansion_wildcard_detector(t_token_list *lst)
// {
// 	t_token_list	*tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		if (lst->type == WORD && lst->lexeme[0] == '$' && lst->lexeme[1] == '*')
// 			return (true);
// 		tmp = tmp->next;
// 	}
// 	return (false);
// }
