/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:41:21 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/11 13:37:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expansion_quotes_runner(char *lexeme)
{
	char	*new_lexeme;

	new_lexeme = malloc(sizeof(char) * (ft_strlen(lexeme) + 1));
	if (new_lexeme == NULL)
		exit(EXIT_FAILURE);
	new_lexeme = expansion_new_lexeme_after_quotes(lexeme, new_lexeme);
	free(lexeme);
	return (new_lexeme);
}

char	*expansion_new_lexeme_after_quotes(char *lexeme, char *new_lexeme)
{
	int		idx;
	int		idx_new;
	char	quote_type;

	idx = -1;
	idx_new = -1;
	quote_type = '\0';
	while (lexeme[++idx])
	{
		if (quote_type == '\0' && (lexeme[idx] == '"' || lexeme[idx] == '\''))
		{
			quote_type = lexeme[idx];
			while (lexeme[++idx])
			{
				new_lexeme[++idx_new] = lexeme[idx];
				if (lexeme[idx] == quote_type)
					break ;
			}
		}
	}
	new_lexeme[idx_new] = '\0';
	return (new_lexeme);
}
