/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   35.manage_or_and.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:31:24 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/02 16:24:30 by umeneses         ###   ########.fr       */
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
