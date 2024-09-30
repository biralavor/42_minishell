/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.tree_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:09:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/01 13:49:34 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tree_execution(t_tree *tree, int *flag)
{
	int	exit_status;

	exit_status = 2;
	if (!tree)
		return (exit_status);
	else if (tree->type == OR)
		exit_status = manage_or(tree);
	else if (tree->type == AND)
		exit_status = manage_and(tree);
	else if (tree->type == PIPE)
		manage_pipe(tree);
	else if (is_redirect(tree->type))
		exit_status = manage_redirect(tree, flag);
	else if (tree->type == SUBSHELL)
		exit_status = manage_subshell(tree);
	else if (tree->type == WORD || tree->type == DOUBLE_QUOTES)
		manage_single_command(tree);
	return (exit_status_holder(0, false));
}
