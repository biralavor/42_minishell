/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:33:44 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 17:13:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_tree_printer(t_tree *root)
{
	t_token_list	*current_command;
	t_token_list	*next_command;

	if (root == NULL)
	{
		fprintf(stderr, "\033[0;33mEmpty Tree\033[0m\n");
		return ;
	}
	if (root->type != 0)
	{
		fprintf(stderr, "|___________________________________________________|\n");
		fprintf(stderr, "|			R.O.O.T.		    |\n");
		fprintf(stderr, "|...........///				\\\\\\.........|\n");
		fprintf(stderr, "|%27s\n", get_token_string(root->type));
	}
	else
		fprintf(stderr, "|%27s\n", get_token_string(root->type));
	current_command = root->command;
	while (current_command)
	{
		fprintf(stderr, "|%25s\n", current_command->lexeme);
		next_command = current_command->next;
		free(current_command);
		current_command = next_command;
	}
	if (root->left)
	{
		fprintf(stderr, "\033[0;32m\n");
		fprintf(stderr, "|__________________________________________________|\n");
		fprintf(stderr, "|-----L.E.F.T.-------------------------------------|\n");
		ft_tree_printer(root->left);
		free(root->left);
		root->left = NULL;
	}
	if (root->right)
	{
		fprintf(stderr, "\033[0;33m\n");
		fprintf(stderr, "|__________________________________________________|\n");
		fprintf(stderr, "|-----------------------------------R.I.G.H.T.-----|\n");
		ft_tree_printer(root->right);
		free(root->right);
		root->right = NULL;
	}
	fflush(stderr);
	free(root);
}
