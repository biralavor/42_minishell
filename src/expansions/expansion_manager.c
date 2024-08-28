/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/28 15:55:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expansion_manager(t_token_list *cmd)
{
	t_token_list	*tmp;
	
	tmp = cmd;
	while (tmp != NULL)
	{
		if (expansion_detector(tmp))
		{
			if (expansion_env_variable_detector(tmp->lexeme))
				tmp->lexeme = expansion_env_variable_runner(tmp->lexeme);
			// else if (expansion_question_mark_detector(tmp))
			// 	return (expansion_question_mark(tmp));
			// else if (expansion_wildcard_detector(tmp))
			// 	return (expansion_wildcard(tmp));
			// else if (expansion_cmd_replace_detector(tmp))
			// 	return (expansion_cmd_replace(tmp));
			// else if (expansion_parameter_detector(tmp))
			// 	return (expansion_parameter(tmp));
			// else
			// 	return (expansion_error(tmp));
		}
		tmp = tmp->next;
	}
}
