/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19.building_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:55:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/12 11:24:03 by umeneses         ###   ########.fr       */
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

t_tree	*get_splited(t_token_list *splited, t_tree *tree)
{
	t_token_list	*left;
	t_token_list	*right;

	tree->type = splited->type;
	right = splited->next;
	if (right)
		right->prev = NULL;
	if (splited->prev)
		left = splited->prev;
	else
		left = NULL;
	if (left)
		left->next = NULL;
	free(splited);
	tree->left = build_tree_recursive(&left);
	tree->right = build_tree_recursive(&right);
	return (tree);

	tree->type = splited->type;
	right = splited->next;
	if (right)
		right->prev = NULL;
	if (splited->prev)
		left = splited->prev;
	else
		left = NULL;
	if (left)
		left->next = NULL;
	free(splited);
	tree->left = build_tree_recursive(&left);
	tree->right = build_tree_recursive(&right);
	return (tree);
}

t_tree	*get_text(t_token_list *lst, t_token_list *splited, t_tree *tree)
{
	t_token_list	*temp;

	temp = go_to_first_node(lst);
	if (!splited)
	{
		tree->type = temp->type;
		tree->command = temp;
	}
	else
	{
		tree->type = splited->type;
		tree->command = splited;
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

t_tree	*build_tree_recursive(t_token_list **lst)
{
	t_token_list	*splited;
	t_tree			*tree_node;

	if (!(*lst))
		return (NULL);
	tree_node = (t_tree *)ft_calloc(1, sizeof(t_tree));
	splited = fetch_token(*lst);
	if (!splited || is_text(splited))
		tree_node = get_text(*lst, splited, tree_node);
	else
		tree_node = get_splited(splited, tree_node);
	return (tree_node);
}

t_tree	*initiate_tree(t_token_list *lst)
{
	return (build_tree_recursive(&lst));
}
