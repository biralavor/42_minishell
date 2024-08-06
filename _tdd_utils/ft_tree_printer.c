/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:33:44 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/06 12:30:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executor.h"
#include "error_manager.h"

void	ft_tree_printer(t_tree *root, int header)
{
	t_tree	*aux;

	aux = root;
	if (root == NULL)
		return ;
	else
	{
		if (header == 0)
		{
			fprintf(stderr, "\033[0;33mPrinting the BINARY TREE Now \033[0m \n");
			fprintf(stderr, "\033[0;31m\n");
			fprintf(stderr, "|___________________________________________________|\n");
			fprintf(stderr, "|			R.O.O.T.		    |\n");
			fprintf(stderr, "|...................///		\\\\\\.................|\n");
			fprintf(stderr, "|\033[0;31m%28s\n", get_token_string(root->type));
		}
		ft_tree_printer(root->left, 1);
		ft_tree_printer(root->right, 2);
		if (header == 1)
		{
			fprintf(stderr, "\033[0;32m\n");
			fprintf(stderr, "|__________________________________________________|\n");
			fprintf(stderr, "|-----L.E.F.T.-------------------------------------|\n");
			if (root->command)
			{
				while (root->command)
				{
					fprintf(stderr, "|	%3s					|\n", root->command->lexeme);
					root->command = root->command->next;
				}
			}
		}
		if (header == 2)
		{
			fprintf(stderr, "\033[0;33m\n");
			fprintf(stderr, "|__________________________________________________|\n");
			fprintf(stderr, "|-----------------------------------R.I.G.H.T.-----|\n");
			if (root->command)
			{
				while (root->command)
				{
					fprintf(stderr, "|			%22s	|\n", root->command->lexeme);
					root->command = root->command->next;
				}
			}
		}
	}
}
