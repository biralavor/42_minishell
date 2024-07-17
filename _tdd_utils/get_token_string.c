/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:19:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/07/16 12:30:59 by tmalheir         ###   ########.fr       */
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
		case SUBSHELL: return "SUBSHELL";
		case ARCHIVE: return "ARCHIVE";
		case DOUBLE_QUOTES: return "DOUBLE QUOTES";
		case SINGLE_QUOTES: return "SINGLE QUOTES";
		default: return "UNKNOWN";
	}
}
