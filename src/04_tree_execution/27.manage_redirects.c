/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.manage_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:20:13 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/01 10:27:53 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	apply_redirect(t_tree *tree, int *fd);
static int	open_redir_file(t_tree *tree, int *fd);
static int	try_open_redir(t_tree *tree, int *new_fd, int *flag, int *std_fd);
static int	finalize_redirect(t_tree *tree, int *flag, int *std_fd);

int	manage_redirect(t_tree *tree, int *flag)
{
	int		std_fd[2];
	int		new_fd;

	new_fd = -1;
	if (tree == NULL)
		return (exit_status_holder(EXIT_SUCCESS, 0));
	std_fd[0] = dup(STDIN_FILENO);
	std_fd[1] = dup(STDOUT_FILENO);
	if (is_redirect(tree->type))
		process_left_redirect(tree, flag);
	if (*flag == -1)
	{
		restore_standard_fds(std_fd);
		return (exit_status_holder(EXIT_SUCCESS, 0));
	}
	if (try_open_redir(tree, &new_fd, flag, std_fd))
		return (exit_status_holder(EXIT_FAILURE, 1));
	finalize_redirect(tree, flag, std_fd);
	return (exit_status_holder(EXIT_SUCCESS, 0));
}

static int	apply_redirect(t_tree *tree, int *fd)
{
	if (tree->type == REDIR_IN || tree->type == REDIR_HDOC)
	{
		if (dup2(*fd, STDIN_FILENO) == -1)
		{
			close(*fd);
			return (exit_status_holder(EXIT_FAILURE, true));
		}
		close(*fd);
	}
	if (tree->type == REDIR_OUT || tree->type == REDIR_OUTAPP)
	{
		if (dup2(*fd, STDOUT_FILENO) == -1)
		{
			close(*fd);
			return (exit_status_holder(EXIT_FAILURE, true));
		}
		close(*fd);
	}
	return (exit_status_holder(EXIT_SUCCESS, true));
}

static int	open_redir_file(t_tree *tree, int *fd)
{
	int		type;
	char	*pathname;

	type = tree->type;
	pathname = ft_strdup(tree->right->command->lexeme);
	pathname = redir_quote_detector(pathname, 0);
	if (type == REDIR_IN || type == REDIR_HDOC)
		*fd = open(pathname, O_RDONLY);
	else if (type == REDIR_OUT)
		*fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == REDIR_OUTAPP)
		*fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*fd < 0)
	{
		perror(pathname);
		free(pathname);
		return (exit_status_holder(1, true));
	}
	free(pathname);
	return (exit_status_holder(0, true));
}

static int	try_open_redir(t_tree *tree, int *new_fd, int *flag, int *std_fd)
{
	if (open_redir_file(tree, new_fd))
	{
		*flag = -1;
		restore_standard_fds(std_fd);
		return (exit_status_holder(EXIT_FAILURE, 1));
	}
	apply_redirect(tree, new_fd);
	return (exit_status_holder(EXIT_SUCCESS, 0));
}

static int	finalize_redirect(t_tree *tree, int *flag, int *std_fd)
{
	if (*flag > 0)
	{
		decrement_flag_and_close_fds(flag, std_fd);
		return (exit_status_holder(EXIT_SUCCESS, 0));
	}
	while (tree->left)
		tree = tree->left;
	if (!is_redirect(tree->type))
		tree_execution(tree, flag);
	restore_standard_fds(std_fd);
	return (exit_status_holder(EXIT_SUCCESS, 0));
}
