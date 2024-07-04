/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.check_userinput.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/03 12:45:08 by tmalheir         ###   ########.fr       */
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
	syntax_analysis(lst);
/*	else if (!check_lexeme(lst))
		error_manager_parser(SYNTAX_ERROR, lst);
	else if (!check_quotes(lst))
		error_manager_parser(COMMAND_NOT_FOUND, lst);*/
}
