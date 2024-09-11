/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_detectors_middle.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/11 13:56:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expansion_dollar_sign_detector(t_token_list *cmd)
{
	int	idx;

	idx = 0;
	while (cmd->lexeme[idx])
	{
		if (cmd->lexeme[idx] == '$')
			return (true);
		idx++;
	}
	return (false);
}

bool	expansion_env_var_detector(char *lexeme)
{
	int	idx;

	idx = 1;
	if (env_var_key_rules_at_start(lexeme[idx]))
	{
		idx++;
		while (lexeme[idx])
		{
			if (env_var_key_rules_at_middle(lexeme[idx]))
				if (lexeme[idx + 1] == '\0')
					return (true);
			idx++;
		}
	}
	return (false);
}

bool	env_var_key_rules_at_start(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (true);
	return (false);
}

bool	env_var_key_rules_at_middle(char c)
{
	if (ft_isdigit(c) || ft_isalpha(c) || c == '_')
		return (true);
	return (false);
}

bool	expansion_quotes_detector(t_token_list *cmd)
{
	if (cmd->type == DOUBLE_QUOTES || cmd->type == SINGLE_QUOTES)
		return (true);
	return (false);
}
