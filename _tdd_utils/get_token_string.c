/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:19:35 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/09 18:44:37 by umeneses         ###   ########.fr       */
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
		case REDIR_IN: return "REDIR_IN";
		case REDIR_HDOC: return "REDIR_HDOC";
		case REDIR_OUT: return "REDIR_OUT";
		case REDIR_OUTAPP: return "REDIR_OUT_APP";
		case OR: return "OR";
		case AND: return "AND";
		case SUBSHELL: return "SUBSHELL";
		case ARCHIVE: return "ARCHIVE";
		case DOUBLE_QUOTES: return "DOUBLE_QUOTES";
		case SINGLE_QUOTES: return "SINGLE_QUOTES";
		default: return "UNKNOWN";
	}
}
