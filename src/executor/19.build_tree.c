/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19.build_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:55:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/18 15:38:25 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "error_manager.h"

void	initiate_tree(t_token_list *lst)
{
	t_tree	*root;

	root = NULL;
	root = build_tree_recursive(&lst);
	if (root)
	{
		ft_printf("Árvore binária impressa.\n");
		print_tree(root);
	}
	else
		ft_printf("Árvore vazia.\n");
}

void	print_tree(t_tree	*root)
{
	if (root != NULL)
	{
		ft_printf("%d\n", root->type);
		print_tree(root->left);
		print_tree(root->right);
	}
}

t_tree	*build_tree_recursive(t_token_list **lst)
{
	t_token_list	*found_node;
	t_token_list	*left_list;
	t_token_list	*right_list;
	t_tree			*tree_node;

	tree_node = (t_tree *)ft_calloc(1, sizeof(t_tree));
	found_node = fetch_token(*lst);
	if (!tree_node || !found_node || !lst)
		return (NULL);
	right_list = found_node->next;
	if (right_list)
		right_list->prev = NULL;
	tree_node->type = found_node->type;
//	tree_node->token = found_node;
	left_list = found_node->prev;
	if (left_list)
		left_list->next = NULL;
	tree_node->left = build_tree_recursive(&left_list);
	tree_node->right = build_tree_recursive(&right_list);
	return (tree_node);
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
	temp = go_to_first_node(lst);
	while (temp && (temp->type != REDIR_IN && temp->type != REDIR_HDOC
			&& temp->type != REDIR_OUT && temp->type != REDIR_OUTAPP))
		temp = temp->next;
	if (temp && (temp->type == REDIR_IN || temp->type == REDIR_HDOC
			|| temp->type == REDIR_OUT || temp->type == REDIR_OUTAPP))
		return (temp);
	temp = go_to_first_node(lst);
	while (temp && temp->type != SUBSHELL)
		temp = temp->next;
	if (temp && temp->type == SUBSHELL)
		return (temp);
	temp = go_to_first_node(lst);
	while (temp && temp->type != WORD && temp->type != ARCHIVE)
		temp = temp->next;
	if (temp && (temp->type == WORD || temp->type == ARCHIVE))
		return (temp);
	return (NULL);
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
