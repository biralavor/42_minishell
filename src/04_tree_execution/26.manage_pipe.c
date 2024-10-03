/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   26.manage_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:51:49 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/03 15:57:36 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	close_pipes(int *new_pipe)
{
	close(new_pipe[0]);
	close(new_pipe[1]);
}

void	exec_2nd_child(t_tree *right, int *new_pipe)
{
	int	flag;

	flag = 0;
	if (NULL == right)
		exit(exit_status_holder(EXIT_FAILURE, true));
	close(new_pipe[1]);
	if (dup2(new_pipe[0], STDIN_FILENO) == -1)
		exit(exit_status_holder(EXIT_FAILURE, true));
	close(new_pipe[0]);
	child_process_is_running(true, true);
	tree_execution(right, &flag);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	clear_all_to_exit_smoothly();
	exit(exit_status_holder(0, false));
}

void	exec_1st_child(t_tree *left, int *new_pipe)
{
	int	flag;

	flag = 0;
	if (NULL == left)
		exit(exit_status_holder(EXIT_FAILURE, true));
	close(new_pipe[0]);
	if (dup2(new_pipe[1], STDOUT_FILENO) == -1)
		exit(exit_status_holder(EXIT_FAILURE, true));
	close(new_pipe[1]);
	child_process_is_running(true, true);
	tree_execution(left, &flag);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	clear_all_to_exit_smoothly();
	exit(exit_status_holder(0, false));
}

bool	child_process_is_running(bool update, bool caller)
{
	static bool	child_process_holder;

	if (update)
		child_process_holder = caller;
	else if (caller)
		return (child_process_holder);
	return (child_process_holder);
}

void	wait_to_restore_fds(int *new_pipe, int *pid)
{
	close_pipes(new_pipe);
	pid_exit_status_caller(pid[0]);
	pid_exit_status_caller(pid[1]);
}

void	manage_pipe(t_tree *tree)
{
	int		new_pipe[2];
	pid_t	pid[2];

	if (!pipe(new_pipe))
	{
		pid[0] = fork();
		if (pid[0] < 0)
			fork_error();
		else if (pid[0] == 0)
		{
			close(new_pipe[0]);
			exec_1st_child(tree->left, new_pipe);
			close(new_pipe[1]);
		}
		pid[1] = fork();
		if (pid[1] < 0)
			fork_error();
		else if (pid[1] == 0)
		{
			close(new_pipe[1]);
			exec_2nd_child(tree->right, new_pipe);
			close(new_pipe[0]);
		}
		wait_to_restore_fds(new_pipe, pid);
	}
	else
		exit_status_holder(EXIT_FAILURE, true);
	close_pipes(new_pipe);
	exit_status_holder(0, false);
}
