/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   31.expansion_detectors.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2026/02/18 19:00:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expansion_dollar_sign_detector(t_token_list *cmd)
{
	int	idx;

	idx = 0;
	if (cmd->prev)
	{
		while (cmd->lexeme && cmd->lexeme[idx] != '\0')
		{
			if (cmd->lexeme[idx] == '$' && cmd->lexeme[idx + 1]
				&& cmd->lexeme[idx + 1] != ' '
				&& ft_strcmp(cmd->prev->lexeme, "unset") != 0)
				return (true);
			idx++;
		}
	}
	else
	{
		while (cmd->lexeme && cmd->lexeme[idx] != '\0')
		{
			if (cmd->lexeme[idx] == '$' && cmd->lexeme[idx + 1]
				&& cmd->lexeme[idx + 1] != ' ')
				return (true);
			idx++;
		}
	}
	return (false);
}

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
