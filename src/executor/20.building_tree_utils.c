/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20.building_tree_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:02:59 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/06 09:22:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "error_manager.h"

bool	is_text(t_token_list *split_token)
{
	if (split_token->type == SUBSHELL || split_token->type == DOUBLE_QUOTES
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
	if (token_tree && token_tree->left)
	{
		free_token_tree(token_tree->left);
		token_tree->left = NULL;
	}
	if (token_tree && token_tree->right)
	{
		free_token_tree(token_tree->right);
		token_tree->right = NULL;
	}
	if (token_tree->command)
		free_token_list(&token_tree->command);
	free(token_tree);
	token_tree = NULL;
}

void	print_tree(t_tree *root)
{
	if (root != NULL)
	{
		ft_printf("%d\n", root->type);
		if (root->command)
		{
			while (root->command)
			{
				ft_printf("%s\n", root->command->lexeme);
				root->command = root->command->next;
			}
		}
		print_tree(root->left);
		print_tree(root->right);
	}
}
