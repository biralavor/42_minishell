/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.check_userinput.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/17 12:55:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	check_userinput(char *str)
// {
// 	t_token_list	*lst;
// 	t_tree			*token_tree;

// 	lst = NULL;
// 	token_tree = NULL;
// 	if (!check_initial_errors(str))
// 		error_manager_lexer(INITIAL_ERROR);
// 	if (!create_token_list(str, &lst))
// 		error_manager_lexer(LIST_NOT_CREATED);
// 	syntax_analysis(lst);
// 	// builtins_manager(lst);
// 	token_tree = initiate_tree(lst);
// 	// ft_tree_printer(token_tree);
// 	free_token_tree(token_tree);
// }


void	loop_routine(char *str)
{
	t_token_list	*lst;
	t_tree			*token_tree;

	lst = NULL;
	token_tree = NULL;
	if (!check_initial_errors(str))
		error_manager_lexer(INITIAL_ERROR);
	if (!create_token_list(str, &lst))
		error_manager_lexer(LIST_NOT_CREATED);
	syntax_analysis(lst);
	token_tree = initiate_tree(lst);
	tree_execution(token_tree);

	free_token_tree(token_tree);
}
