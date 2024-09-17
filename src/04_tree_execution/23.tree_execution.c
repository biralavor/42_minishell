/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.tree_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:09:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/17 09:58:15 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tree_execution(t_tree *tree, int flag)
{
	int	exit_status;

	exit_status = 2;
	ft_lst_printer(tree->command);
	if (!tree)
		return (exit_status);
	else if (tree->type == OR)
		exit_status = manage_or(tree);
	else if (tree->type == AND)
		exit_status = manage_and(tree);
	else if (tree->type == PIPE)
		exit_status = manage_pipe(tree);
	else if (is_redirect(tree->type))
		exit_status = manage_redirect(tree, flag);
	else if (tree->type == SUBSHELL)
		exit_status = manage_subshell(tree);
	else if (tree->type == WORD)
		exit_status = manage_single_command(tree);
	return (exit_status);
}
