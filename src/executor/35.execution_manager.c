/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3555.execution_manager.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:31:24 by tmalheir          #+#    #+#             */
/*   Updated: 2024/08/29 12:54:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_or(t_tree *tree)
{
	int	exit_status;

	exit_status = tree_execution(tree->left);
	if (exit_status)
		exit_status = tree_execution(tree->right);
	return (exit_status);
}

int	manage_and(t_tree *tree)
{
	int	exit_status;

	exit_status = tree_execution(tree->left);
	if (!exit_status)
		exit_status = tree_execution(tree->right);
	return (exit_status);
}

int	manage_pipe(t_tree *tree)
{
	int	exit_status;

	exit_status = tree_execution(tree->left);
	return (exit_status);
}