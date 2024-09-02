/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   36.manage_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:51:49 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/02 12:01:41 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_pipe(t_tree *tree)
{
	int		exit_status[2];
	int		new_pipe[2];
	pid_t	pid[2];

	if (!pipe(new_pipe))
	{
		pid[0] = fork();
		if (pid[0] == -1)
			return (fork_error());
		else if (pid[0] == 0)
			exec_1st_child(tree->left, new_pipe);
		pid[1] = fork();
		if (pid[1] == -1)
			return (fork_error());
		else if (pid[1] == 0)
			exec_2nd_child(tree->right, new_pipe);
		close(new_pipe[0]);
		close(new_pipe[1]);
		waitpid(pid[0], &exit_status[0], 0);
		waitpid(pid[1], &exit_status[1], 0);
	}
	return (exit_status_holder(exit_status[1]));
}

void	exec_1st_child(t_tree *left, int *new_pipe)
{
	int	exit_status;

	close(new_pipe[0]);
	dup2(new_pipe[1], STDOUT_FILENO);
	close(new_pipe[1]);
	exit_status = tree_execution(left);
	exit(exit_status);
}

void	exec_2nd_child(t_tree *right, int *new_pipe)
{
	int	exit_status;

	close(new_pipe[1]);
	dup2(new_pipe[0], STDIN_FILENO);
	close(new_pipe[0]);
	exit_status = tree_execution(right);
	exit(exit_status);
}
