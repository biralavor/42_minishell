/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18.build_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:55:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/07/11 10:07:19 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "error_manager.h"

void	initiate_tree(t_token_list *lst)
{
	t_token_list	*temp;

	temp = lst;
	while (temp->next)
		temp = temp->next;
	build_tree_recursive(&temp);
}

t_tree	*build_tree_recursive(t_token_list **lst)
{
	t_token_list	*temp;
	t_token_list	*left_end;
	t_token_list	*right_start;
	t_tree			*tree_node;

	if (!lst || !(*lst))
		return (NULL);
	tree_node = (t_tree *)ft_calloc(1, sizeof(t_tree));
	temp = *lst;
	if (temp->type == OR || temp->type == AND)
	{
		tree_node->type = temp->type;
		tree_node->token = temp;
		left_end = temp->prev;
		right_start = temp->next;
		tree_node->tree_left = build_tree_recursive(&left_end);
		tree_node->tree_right = build_tree_recursive(&right_start);
	}
	if (temp->type == WORD)
	{
		tree_node->type = temp->type;
		tree_node->token = temp;
		left_end = temp->prev;
		right_start = temp->next;
		tree_node->tree_left = build_tree_recursive(&left_end);
		tree_node->tree_right = build_tree_recursive(&right_start);
	}
	return (tree_node);
}
