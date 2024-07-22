/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20.building_tree_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:02:59 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/22 15:43:05 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "error_manager.h"

bool	is_text(t_token_list *split_token)
{
	if (split_token->type == SUBSHELL ||split_token->type == DOUBLE_QUOTES
		|| split_token->type == SINGLE_QUOTES)
		return (true);
	return (false);
}

t_token_list	*go_to_last_node(t_token_list *lst)
{
	t_token_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node->next)
		node = node->next;
	return (node);
}

t_token_list	*go_to_first_node(t_token_list *lst)
{
	t_token_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node->prev)
		node = node->prev;
	return (node);
}

void	free_token_tree(t_tree *token_tree)
{
	if (!token_tree)
		return ;
	if (token_tree->left)
		free_token_tree(token_tree->left);
	if (token_tree->right)
		free_token_tree(token_tree->right);
	free(token_tree);
}