/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   36.expansion_question.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:32:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/19 20:14:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expansion_question_mark(char *lexeme)
{
	char	*new_lex;
	char	**splited;
	int		id;
	int		idx;
	int		len;

	idx = 0;
	id = -1;
	splited = NULL;
	len = ft_strlen(lexeme);
	splited = (char **)ft_calloc(len + 1, sizeof(char *));
	while (lexeme[idx])
	{
		if (lexeme[idx] == '?' && lexeme[idx - 1] == '$')
		{
			splited[++id] = ft_substr(lexeme, 0, --idx);
			splited[++id] = ft_itoa(exit_status_holder(0, false));
			idx += 2;
			if (lexeme[idx])
				splited[++id] = ft_substr(lexeme, idx, len - idx);
		}
		idx++;
	}
	id = 0;
	new_lex = ft_strdup(splited[id]);
	id++;
	while (splited[id])
	{
		new_lex = ft_strjoin(new_lex, splited[id]);
		id++;
	}
	free_array(splited);
	free(lexeme);
	return (new_lex);
}
