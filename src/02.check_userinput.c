/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.check_userinput.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:20:45 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/09 16:22:29 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
void	check_userinput(char *str)
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
	// builtins_manager(lst);
	token_tree = initiate_tree(lst);
	// ft_tree_printer(token_tree);
	tree_execution(token_tree);
	free_token_tree(token_tree);
}
*/

/*
t_tree	*test_tree(void)
{
	t_tree	*tree;

	tree = calloc(sizeof(t_tree), 1);
	tree->type = REDIR_OUT;

	tree->right = calloc(sizeof(t_tree), 1);
	tree->right->type = ARCHIVE;
	create_token_list("tudo", &tree->right->command);

	tree->left = calloc(sizeof(t_tree), 1);
	tree->left->type = REDIR_OUT;

	tree->left->right = calloc(sizeof(t_tree), 1);
	tree->left->right->type = ARCHIVE;
	create_token_list("bem", &tree->left->right->command);

	tree->left->left = calloc(sizeof(t_tree), 1);
	tree->left->left->type = REDIR_OUT;

	tree->left->left->right = calloc(sizeof(t_tree), 1);
	tree->left->left->right->type = ARCHIVE;
	create_token_list("com", &tree->left->left->right->command);

	tree->left->left->left = calloc(sizeof(t_tree), 1);
	tree->left->left->left->type = REDIR_IN;

	tree->left->left->left->right = calloc(sizeof(t_tree), 1);
	tree->left->left->left->right->type = ARCHIVE;
	create_token_list("voce", &tree->left->left->left->right->command);

	tree->left->left->left->left = calloc(sizeof(t_tree), 1);
	tree->left->left->left->left->type = WORD;
	create_token_list("ls", &tree->left->left->left->left->command);

	return (tree);
}
*/

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
	if (syntax_analysis(lst))
	{
		token_tree = initiate_tree(lst);
		// token_tree = test_tree();
		// ft_tree_printer(token_tree);
		tree_execution(token_tree);
		free_token_tree(token_tree);
	}
}
