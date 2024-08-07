/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05.get_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:51 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/16 11:40:30 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "error_manager.h"

void	get_state(int idx, char *str, t_token_list **lst)
{
	while (str[idx])
	{
		if (str[idx] == '(')
			idx = state_20(lst, str, idx);
		else if (str[idx] == '|')
			idx = state_30(lst, str[idx], str[idx + 1], idx);
		else if (str[idx] == '&' && str[idx + 1] == '&')
			idx = state_40(lst, idx, str[idx + 1]);
		else if (str[idx] == '>')
			idx = state_50(lst, str[idx], str[idx + 1], idx);
		else if (str[idx] == '<')
			idx = state_60(lst, str[idx], str[idx + 1], idx);
		else if (str[idx] == '"')
			idx = state_70(lst, str, idx);
		else if (str[idx] == '\'')
			idx = state_80(lst, str, idx);
		else if ((str[idx] != '(') && (str[idx] != ')') && (str[idx] != '|')
			&& (str[idx] != '>') && (str[idx] != '<')
			&& (str[idx] != '"') && (str[idx] != '\''))
			idx = state_90(lst, str, idx);
		else
			lexer_error();
	}
}
