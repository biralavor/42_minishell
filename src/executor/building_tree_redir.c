/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   building_tree_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 08:36:23 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/10 09:29:16 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*tree_with_redir(t_token_list *split, t_token_list *lst, t_tree *node)
{
	t_token_list	*temp_lst;
	t_token_list	*temp_split;

	temp_lst = lst;
	temp_split = NULL;
	node->type = split->type;
	node->right = get_archive(split);
	node->right->type = split->next->type;
	node->right->command = split->next;
	if (split->next->next)
	{
		temp_split = split->next->next;
		if (is_redirect(temp_split->type))
			node->left = tree_with_redir(temp_split, lst, node->left);
	}
	else
	{
		while (!is_redirect(temp_lst->next->type))
			temp_lst = temp_lst->next;
		temp_lst->next = NULL;
		temp_lst = go_to_first_node(temp_lst);
		node->left->type = temp_lst->type;
		node->left->command = temp_lst;
	}
	return (node);
}

static t_tree	*get_archive(t_token_list *split)
{
	
}
	node->right = (t_tree *)ft_calloc(1, sizeof(t_tree));