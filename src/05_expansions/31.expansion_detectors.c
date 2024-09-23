/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   31.expansion_detectors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/21 15:07:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expansion_dollar_sign_detector(t_token_list *cmd)
{
	int	idx;

	idx = 0;
	while (cmd->lexeme && cmd->lexeme[idx] != '\0')
	{
		if (cmd->lexeme[idx] == '$' && cmd->lexeme[idx + 1]
			&& cmd->lexeme[idx + 1] != ' ')
			return (true);
		idx++;
	}
	return (false);
}

// bool	expansion_env_var_detector(char *lexeme)
// {
// 	int	idx;

// 	idx = -1;
// 	while (lexeme[++idx])
// 	{
// 		if (env_var_key_rules_at_start(lexeme[idx]))
// 		{
// 			idx++;
// 			while (lexeme[idx])
// 			{
// 				if (env_var_key_rules_at_middle(lexeme[idx]))
// 					if (lexeme[idx + 1] == '\0')
// 						return (true);
// 				idx++;
// 			}
// 		}
// 	}
// 	return (false);
// }

bool	quotes_detector(t_token_list *cmd)
{
	if (cmd->type == DOUBLE_QUOTES || cmd->type == SINGLE_QUOTES)
		return (true);
	return (false);
}

bool	expansion_question_mark_detector(char *lexeme)
{
	int	idx;

	idx = 0;
	while (lexeme[idx])
	{
		if (lexeme[idx] == '?' && lexeme[idx - 1] == '$')
			return (true);
		idx++;
	}
	return (false);
}

// bool	expansion_wildcard_detector(char *lexeme)
// {
// 	if (lexeme[1] == '*' && lexeme[2] == '\0')
// 		return (true);
// 	return (false);
// }