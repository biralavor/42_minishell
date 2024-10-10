/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.tree_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:09:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 12:29:28 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tree_execution(t_tree *tree, int *flag)
{
	if (!tree)
		return ;
	else if (tree->type == OR)
		manage_or(tree);
	else if (tree->type == AND)
		manage_and(tree);
	else if (tree->type == PIPE)
		manage_pipe(tree);
	else if (is_redirect(tree->type))
		manage_redirect(tree, flag);
	else if (tree->type == SUBSHELL)
		manage_subshell(tree);
	else if (tree->type == WORD || tree->type == DOUBLE_QUOTES
		|| tree->type == SINGLE_QUOTES)
		manage_single_command(tree);
}
