/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:19:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/12 19:24:11 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"

/**
 * @brief: To get the string of the enum e_token
*/
char	*get_token_string(enum e_token token)
{
	switch (token)
	{
		case WORD: return "WORD";
		case PIPE: return "PIPE";
		case REDIRECT_INPUT: return "REDIRECT_INPUT";
		case REDIRECT_HEREDOC: return "REDIRECT_HEREDOC";
		case REDIRECT_OUTPUT: return "REDIRECT_OUTPUT";
		case REDIRECT_OUTPUT_APPEND: return "REDIRECT_OUTPUT_APPEND";
		case OR: return "OR";
		case AND: return "AND";
		case OPEN_PARENTHESIS: return "OPEN_PARENTHESIS";
		case CLOSE_PARENTHESIS: return "CLOSE_PARENTHESIS";
		default: return "UNKNOWN";
	}
}
