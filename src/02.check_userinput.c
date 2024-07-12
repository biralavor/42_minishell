/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.check_userinput.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/12 18:42:17 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "error_manager.h"

void	check_userinput(char *str)
{
	t_token_list	*lst;

	lst = NULL;
	if (!check_initial_errors(str))
		error_manager_lexer(LEXER_ERROR);
	if (!create_token_list(str, &lst))
		error_manager_lexer(LIST_NOT_CREATED);
	syntax_analysis(lst);
	// build_tree(lst);
	free(lst);
}
