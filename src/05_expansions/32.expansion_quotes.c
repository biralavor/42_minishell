/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   32.expansion_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:41:21 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/07 16:25:26 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	single_quote_detector(char *lexeme)
{
	int		idx;

	idx = 0;
	while (lexeme[idx])
	{
		if (lexeme[idx] == '\'')
			return (true);
		idx++;
	}
	return (false);
}

char	*single_quote_remover(char *lex)
{
	int		idx;

	idx = 0;
	if (lex[idx] == '\'' && lex[idx + 1] == '\'' && !lex[idx + 2])
	{
		free(lex);
		lex = NULL;
		return (lex);
	}
	while (lex[idx])
	{
		if (lex[idx] == '\'')
		{
			ft_memmove(&lex[idx], &lex[idx + 1], ft_strlen(&lex[idx + 1]) + 1);
			if (idx)
				idx--;
		}
		if(lex[idx] != '\'')
			idx++;
	}
	return (lex);
}

bool	double_quote_detector(char *lexeme)
{
	int	idx;

	idx = 0;
	if (lexeme)
	{
		while (lexeme[idx])
		{
			if (lexeme[idx] == '"')
				return (true);
			idx++;
		}
	}
	return (false);
}

char	*double_quote_remover(char *lex)
{
	int		idx;

	idx = 0;
	if (lex[idx] == '"' && lex[idx + 1] == '"' && !lex[idx + 2])
	{
		free(lex);
		lex = NULL;
		return (lex);
	}
	while (lex[idx])
	{
		if (lex[idx] == '"')
		{
			ft_memmove(&lex[idx], &lex[idx + 1], ft_strlen(&lex[idx + 1]) + 1);
			if (idx)
				idx--;
		}
		if(lex[idx] != '"')
			idx++;
	}
	return (lex);
}
