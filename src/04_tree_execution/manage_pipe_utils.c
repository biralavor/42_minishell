/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pipe_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:49:47 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/04 14:03:23 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipes(int *new_pipe)
{
	close(new_pipe[0]);
	close(new_pipe[1]);
}

void	prepare_1st_child(t_tree *tree, int *new_pipe)
{
	close(new_pipe[0]);
	exec_1st_child(tree->left, new_pipe);
	close(new_pipe[1]);
}

void	prepare_2nd_child(t_tree *tree, int *new_pipe)
{
	close(new_pipe[1]);
	exec_2nd_child(tree->right, new_pipe);
	close(new_pipe[0]);
}
