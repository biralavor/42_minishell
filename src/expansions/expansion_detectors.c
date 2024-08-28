/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_detectors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:31:10 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/28 18:49:44 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expansion_detector(t_token_list *cmd)
{
	if (cmd->type == WORD && cmd->lexeme[0] == '$')
		return (true);
	return (false);
}

bool	expansion_env_variable_detector(char *lexeme)
{
	if (ft_isalpha(lexeme[1]) || lexeme[1] == '_')
		return (true);
	return (false);
}

bool	expansion_question_mark_detector(char *lexeme)
{
	if (lexeme[1] == '?' || lexeme[2] == '\0')
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

// bool	expansion_cmd_replace_detector(t_token_list *lst)
// {
// 	t_token_list	*tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		if (lst->type == WORD && lst->lexeme[0] == '$' && lst->lexeme[1] == '(')
// 			return (true);
// 		tmp = tmp->next;
// 	}
// 	return (false);
// }

// bool	expansion_parameter_detector(t_token_list *lst)
// {
// 	t_token_list	*tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		if (lst->type == WORD && lst->lexeme[0] == '$' && lst->lexeme[1] == '{')
// 			return (true);
// 		tmp = tmp->next;
// 	}
// 	return (false);
// }