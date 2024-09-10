/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19.building_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:55:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/12 10:29:19 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*tree_holder(t_tree *tree, bool clear)
{
	static t_tree	*tree_holder;

	if (tree)
		tree_holder = tree;
	else if (tree_holder && clear)
	{
		free_token_tree(tree_holder);
		tree_holder = NULL;
	}
	return (tree_holder);
}

t_tree	*initiate_tree(t_token_list *lst)
{
	return (build_tree_recursive(&lst));
}

t_tree	*build_tree_recursive(t_token_list **lst)
{
	t_token_list	*split;
	t_token_list	*left;
	t_token_list	*right;
	t_tree			*tree_node;

	if (!(*lst))
		return (NULL);
	tree_node = (t_tree *)ft_calloc(1, sizeof(t_tree));
	split = fetch_token(*lst);
	if (!split || is_text(split))
		tree_node = text(*lst, split, tree_node);
	else
	{
		tree_node->type = split->type;
		right = split->next;
		if (right)
			right->prev = NULL;
		if (split->prev)
			left = split->prev;
		else
			left = NULL;
		if (left)
			left->next = NULL;
		free(split);
		tree_node->left = build_tree_recursive(&left);
		tree_node->right = build_tree_recursive(&right);
	}
	return (tree_node);
}

t_tree	*text(t_token_list *lst, t_token_list *split, t_tree *tree)
{
	t_token_list	*temp;

	temp = go_to_first_node(lst);
	if (!split)
	{
		tree->type = temp->type;
		tree->command = temp;
	}
	else
	{
		tree->type = split->type;
		tree->command = split;
	}
	return (tree);
}

t_token_list	*fetch_token(t_token_list *lst)
{
	t_token_list	*temp;

	temp = go_to_last_node(lst);
	while (temp && (temp->type != OR && temp->type != AND))
		temp = temp->prev;
	if (temp && (temp->type == OR || temp->type == AND))
		return (temp);
	temp = go_to_last_node(lst);
	while (temp && temp->type != PIPE)
		temp = temp->prev;
	if (temp && temp->type == PIPE)
		return (temp);
	temp = go_to_last_node(lst);
	while (temp && (!is_redirect(temp->type)))
		temp = temp->prev;
	if (temp && (is_redirect(temp->type)))
		return (temp);
/*	temp = go_to_first_node(lst);
	while (temp && temp->type != SUBSHELL)
		temp = temp->next;
	if (temp && temp->type == SUBSHELL)
		return (temp);*/
	return (NULL);
}
