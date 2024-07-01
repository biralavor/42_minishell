/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:49:51 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/01 15:06:06 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

void	get_state(int idx, char *str, t_token_list **lst)
{
	while (str[idx])
	{
		if (str[idx] == '(')
			idx = state_1(lst, idx);
		else if (str[idx] == ')')
			idx = state_2(lst, idx);
		else if (str[idx] == '|')
			idx = state_3(lst, str[idx], str[idx + 1], idx);
		else if (str[idx] == '&' && str[idx + 1] == '&')
			idx = state_6(lst, idx);
		else if (str[idx] == '>')
			idx = state_7(lst, str[idx], str[idx + 1], idx);
		else if (str[idx] == '<')
			idx = state_10(lst, str[idx], str[idx + 1], idx);
		else if (str[idx] == '"')
			idx = state_13(lst, str, idx);
		else if (str[idx] == '\'')
			idx = state_14(lst, str, idx);
		else if ((str[idx] != '(') && (str[idx] != ')') && (str[idx] != '|')
			&& (str[idx] != '>') && (str[idx] != '<')
			&& (str[idx] != '"') && (str[idx] != '\''))
			idx = state_15(lst, str, idx);
		else
			lexer_error();
	}
}
