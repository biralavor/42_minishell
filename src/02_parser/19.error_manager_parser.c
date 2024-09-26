/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19.error_manager_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:53:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/26 14:55:14 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_manager_parser(int error_id, t_token_list *lst, int syntax_state)
{
	if (error_id == UNEXPECTED_TOKEN)
	{
		if (!lst->lexeme && syntax_state == 201)
			lst->lexeme = ft_strdup("|");
		else if (!lst->lexeme && syntax_state == 301 && !lst->next)
			lst->lexeme = ft_strdup("newline");
		else if (!lst->lexeme && syntax_state == 301 && lst->next)
			lst->lexeme = get_metachar_type_as_str(lst->next->type);
		unexpected_token_error(lst->lexeme);
	}
	else if (error_id == SYNTAX_ERROR)
		syntax_error();
}

void	unexpected_token_error(char *lex)
{
	ft_putstr_fd(" syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(lex, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

void	syntax_error(void)
{
	ft_putendl_fd("syntax error.\n", STDERR_FILENO);
	ft_putendl_fd("'\\', '&' or ';' detected\n", STDERR_FILENO);
}

char	*get_metachar_type_as_str(int type)
{
	char *result;

	result = NULL;
	if (type == PIPE)
		result = ft_strdup("|");
	else if (type == AND)
		result = ft_strdup("&&");
	else if (type == OR)
		result = ft_strdup("||");
	else if (type == DOUBLE_QUOTES)
		result = ft_strdup("\"");
	else if (type == SINGLE_QUOTES)
		result = ft_strdup("'");
	else if (type == SUBSHELL)
		result = ft_strdup("()");
	else if (type == REDIR_OUT)
		result = ft_strdup(">");
	else if (type == REDIR_OUTAPP)
		result = ft_strdup(">>");
	else if (type == REDIR_IN)
		result = ft_strdup("<");
	else if (type == REDIR_HDOC)
		result = ft_strdup("<<");
	return (result);
}
