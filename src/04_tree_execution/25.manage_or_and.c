/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25.manage_or_and.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:31:24 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/04 18:01:42 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_or(t_tree *tree)
{
	tree_execution(tree->left, 0);
	if (exit_status_holder(0, false) != 0)
		tree_execution(tree->right, 0);
}

void	manage_and(t_tree *tree)
{
	tree_execution(tree->left, 0);
	if (exit_status_holder(0, false) == 0)
		tree_execution(tree->right, 0);
}
