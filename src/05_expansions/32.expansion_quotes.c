/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32.expansion_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:41:21 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/19 19:44:23 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	single_quote_detector(char *lexeme)
{
	if (lexeme[0] == '\'')
			return (true);
	return (false);
}

char	*single_quote_remover(char *lex)
{
	int		idx;

	idx = 0;
	while (lex[idx])
	{
		if (lex[idx] == '\'')
			ft_memmove(&lex[idx], &lex[idx + 1], ft_strlen(&lex[idx + 1]) + 1);
		idx++;
	}
	return (lex);
}
