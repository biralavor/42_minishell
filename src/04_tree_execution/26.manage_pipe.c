/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   26.manage_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:51:49 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/22 11:13:49 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
static void	free_child_proccess(t_tree *tree)
{
	free_token_tree(token_tree)
}
*/
static void	close_pipes(int *new_pipe)
{
	close(new_pipe[0]);
	close(new_pipe[1]);
}

void	exec_2nd_child(t_tree *right, int *new_pipe)
{
	if (NULL == right)
		exit(exit_status_holder(EXIT_FAILURE, true));
	close(new_pipe[1]);
	if (dup2(new_pipe[0], STDIN_FILENO) == -1)
		exit(exit_status_holder(EXIT_FAILURE, true));
	close(new_pipe[0]);
	child_process_is_running(true, true);
	tree_execution(right, 0);
	// printf("\n\nexit code at exec_2nd_child RIGHT = %d\n\n", exit_status_holder(0, false));
	// close(STDERR_FILENO);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	clear_all_to_exit_smoothly();
	exit(exit_status_holder(0, true));
}

void	exec_1st_child(t_tree *left, int *new_pipe)
{
	if (NULL == left)
		exit(exit_status_holder(EXIT_FAILURE, true));
	close(new_pipe[0]);
	if (dup2(new_pipe[1], STDOUT_FILENO) == -1)
		exit(exit_status_holder(EXIT_FAILURE, true));
	close(new_pipe[1]);
	child_process_is_running(true, true);
	tree_execution(left, 0);
	// printf("\n\nexit code at exec_1st_child LEFT = %d\n\n", exit_status_holder(0, false));
	// close(STDERR_FILENO);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	clear_all_to_exit_smoothly();
	exit(exit_status_holder(0, true));
}

bool	child_process_is_running(bool update, bool caller)
{
	static bool child_process_holder;

	if (update && caller)
		child_process_holder = caller;
	else if (caller)
		return (child_process_holder);
	return (child_process_holder);	
}

void	wait_to_restore_fds(int *new_pipe, int *pid)
{
	close_pipes(new_pipe);
	// waitpid(pid[0], &exit_status, 0);
	pid_exit_status_caller(pid[0]);
	// printf("\n\nwait_to_restore_fds ::: exit code at pid[0] = %d\n\n", exit_status_holder(0, false));
	// waitpid(pid[1], &exit_status, 0);
	pid_exit_status_caller(pid[1]);
	// printf("\n\nwait_to_restore_fds ::: exit code at pid[1] = %d\n\n", exit_status_holder(0, false));
}

void	manage_pipe(t_tree *tree)
{
	// int		exit_status;
	int		new_pipe[2];
	pid_t	pid[2];
	// int		duplicate_stdout;
	// int		duplicate_stdin;

	// exit_status = 0;
	if (!pipe(new_pipe))
	{
		// duplicate_stdout = dup(STDOUT_FILENO);
		// duplicate_stdin = dup(STDIN_FILENO);
		pid[0] = fork();
		if (pid[0] < 0)
			fork_error();
		else if (pid[0] == 0)
		{
			close(new_pipe[0]);
			exec_1st_child(tree->left, new_pipe);
			close(new_pipe[1]);
			exit(exit_status_holder(EXIT_SUCCESS, true));
		}
		// dup2(duplicate_stdout, STDOUT_FILENO);
		// close(duplicate_stdout);
		// close(new_pipe[1]);
		pid[1] = fork();
		if (pid[1] < 0)
			fork_error();
		else if (pid[1] == 0)
		{
			close(new_pipe[1]);
			exec_2nd_child(tree->right, new_pipe);
			close(new_pipe[0]);
			exit(exit_status_holder(EXIT_SUCCESS, true));
		}
		// dup2(duplicate_stdin, STDIN_FILENO);
		// close(duplicate_stdin);
		close(new_pipe[0]);
		close(new_pipe[1]);
		wait_to_restore_fds(new_pipe, pid);
	}
	else
		exit_status_holder(EXIT_FAILURE, true);
	close_pipes(new_pipe);
	exit_status_holder(0, false);
}
