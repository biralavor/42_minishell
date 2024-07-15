/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:19:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/15 10:06:17 by umeneses         ###   ########.fr       */
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
		case REDIR_IN: return "REDIRECT_INPUT";
		case REDIR_HDOC: return "REDIRECT_HEREDOC";
		case REDIR_OUT: return "REDIRECT_OUTPUT";
		case REDIR_OUTAPP: return "REDIRECT_OUTPUT_APPEND";
		case OR: return "OR";
		case AND: return "AND";
		case OPEN_PARENTHESIS: return "OPEN_PARENTHESIS";
		case CLOSE_PARENTHESIS: return "CLOSE_PARENTHESIS";
		default: return "UNKNOWN";
	}
}
