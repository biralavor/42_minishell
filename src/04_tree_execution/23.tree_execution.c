/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.tree_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:09:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/04 17:40:22 by umeneses         ###   ########.fr       */
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
	else if (tree->type == WORD || tree->type == DOUBLE_QUOTES)
		manage_single_command(tree);
}
