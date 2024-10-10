/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_pipe_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:49:47 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/10 10:04:01 by umeneses         ###   ########.fr       */
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
	signal(SIGPIPE, SIG_IGN);
	close(new_pipe[0]);
	exec_1st_child(tree->left, new_pipe);
	close(new_pipe[1]);
}

void	prepare_2nd_child(t_tree *tree, int *new_pipe)
{
	signal(SIGPIPE, SIG_IGN);
	close(new_pipe[1]);
	exec_2nd_child(tree->right, new_pipe);
	close(new_pipe[0]);
}
