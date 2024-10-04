/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   36.expansion_question.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:32:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/04 15:02:13 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_splited_parts(char **splited)
{
	int		id;
	char	*new_lex;
	char	*tmp;

	id = 0;
	new_lex = ft_strdup(splited[id]);
	tmp = NULL;
	id++;
	while (splited[id])
	{
		tmp = ft_strjoin(new_lex, splited[id]);
		free(new_lex);
		new_lex = tmp;
		id++;
	}
	return (new_lex);
}

// static void	add_substring(char ***splited, char *lexeme, int *id, int *idx)
// {
// 	(*splited)[(*id)++] = ft_substr(lexeme, 0, (*idx)--);
// 	(*splited)[(*id)++] = ft_itoa(exit_status_holder(0, false));
// 	(*idx) += 2;
// }

char	*expansion_question_mark(char *lexeme)
{
	char	*new_lex;
	char	**splited;
	int		id;
	int		idx;

	idx = 0;
	id = -1;
	splited = (char **)ft_calloc(ft_strlen(lexeme) + 1, sizeof(char *));
	while (lexeme[idx++])
	{
		if (lexeme[idx] == '?' && lexeme[idx - 1] == '$')
		{
			splited[++id] = ft_substr(lexeme, 0, --idx);
			splited[++id] = ft_itoa(exit_status_holder(0, false));
			idx += 2;
			if (lexeme[idx])
				splited[++id] = ft_substr(lexeme, idx, ft_strlen(lexeme) - idx);
			else
				break ;
		}
	}
	new_lex = join_splited_parts(splited);
	free_array(splited);
	free(lexeme);
	return (new_lex);
}
