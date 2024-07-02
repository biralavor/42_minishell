/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_userinput.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/01 22:19:05 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"

void	check_userinput(char *str)
{
	t_token_list	*lst;

	lst = NULL;
	if (!(check_initial_errors(str)))
		error_manager_lexer(LEXER_ERROR);
	else if (!create_token_list(str, &lst))
		error_manager_lexer(LIST_NOT_CREATED);
	else if (!check_first_node(lst))
		error_manager_parser(UNEXPECTED_TOKEN, lst);
	else if (!check_lexeme(lst))
		error_manager_parser(SYNTAX_ERROR, lst);
	else if (!check_quotes(lst))
		error_manager_parser(COMMAND_NOT_FOUND, lst);
	else if (!check_closed_parenthesis(lst))
		error_manager_parser(PARENTHESIS_ERROR, lst);
	free_token_list(&lst);
}
