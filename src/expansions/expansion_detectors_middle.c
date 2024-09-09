/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_detectors_middle.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 10:40:43 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expansion_detector_at_middle(t_token_list *cmd)
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

bool	expansion_env_var_detector_at_middle(t_token_list *cmd)
{
	int	idx;

	idx = 0;
	while (cmd->lexeme[idx])
	{
		if (cmd->lexeme[idx] == '$')
		{
			idx++;
			if (ft_isalpha(cmd->lexeme[idx]) || cmd->lexeme[idx] == '_')
				return (true);
		}
		idx++;
	}
	
	return (false);
}
