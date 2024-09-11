/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   36.manage_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:51:49 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/11 11:51:32 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
static void	free_child_proccess(t_tree *tree)
{
	free_token_tree(token_tree)
}
*/
static void	close_pipe(int *new_pipe)
{
	close(new_pipe[0]);
	close(new_pipe[1]);
}

void	exec_2nd_child(t_tree *right, int *new_pipe)
{
	int	exit_status;

	exit_status = 0;
	close(new_pipe[1]);
	dup2(new_pipe[0], STDIN_FILENO);
	close(new_pipe[0]);
	exit_status = tree_execution(right, 0);
	// close(STDERR_FILENO);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	(void)exit_status;
	exit(0);
//	free_token_tree(right);
	// exit(exit_status); remover, já que é importante verificar se deu certo
}

void	exec_1st_child(t_tree *left, int *new_pipe)
{
	int	exit_status;

	exit_status = 0;
	close(new_pipe[0]);
	dup2(new_pipe[1], STDOUT_FILENO);
	close(new_pipe[1]);
	exit_status = tree_execution(left, 0);
	// close(STDERR_FILENO);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	(void)exit_status;
	exit(0);
//	free_token_tree(left);
	// exit(exit_status); remover, já que é importante verificar se deu certo
}

int	manage_pipe(t_tree *tree)
{
	int		exit_status;
	int		new_pipe[2];
	pid_t	pid[2];
	// int		duplicate_stdout;
	// int		duplicate_stdin;

	exit_status = 0;
	if (!pipe(new_pipe))
	{
		// duplicate_stdout = dup(STDOUT_FILENO);
		// duplicate_stdin = dup(STDIN_FILENO);
		pid[0] = fork();
		if (pid[0] == -1)
			return (fork_error());
		else if (pid[0] == 0)
			exec_1st_child(tree->left, new_pipe);
		// dup2(duplicate_stdout, STDOUT_FILENO);
		// close(duplicate_stdout);
		// close(new_pipe[1]);
		pid[1] = fork();
		if (pid[1] == -1)
			return (fork_error());
		else if (pid[1] == 0)
			exec_2nd_child(tree->right, new_pipe);
		// dup2(duplicate_stdin, STDIN_FILENO);
		// close(duplicate_stdin);
		close_pipe(new_pipe);
		waitpid(pid[0], &exit_status, 0);
		waitpid(pid[1], &exit_status, 0);
	}
	// return pid_exit_status_caller;
	return ((exit_status));
}
