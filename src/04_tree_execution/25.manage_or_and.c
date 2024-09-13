/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   35.manage_or_and.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:31:24 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/10 13:32:44 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_or(t_tree *tree)
{
	int	exit_status;

	exit_status = tree_execution(tree->left, 0);
	if (exit_status)
		exit_status = tree_execution(tree->right, 0);
	return (exit_status);
}

int	manage_and(t_tree *tree)
{
	int	exit_status;

	exit_status = tree_execution(tree->left, 0);
	if (!exit_status)
		exit_status = tree_execution(tree->right, 0);
	return (exit_status);
}
