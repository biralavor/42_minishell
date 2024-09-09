/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_detectors_middle.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 10:12:57 by umeneses         ###   ########.fr       */
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
			if (ft_isalpha(cmd->lexeme[idx]) || cmd->lexeme[idx] == '_')
				return (true);
		idx++;
	}
	
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
