/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.manage_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:20:13 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/30 16:51:49 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static char	*quote_detector(char *lexeme, int *flag)
{
	int		idx;

	idx = 0;
	while (lexeme[idx])
	{
		if (lexeme[idx] == '\'')
		{
			*flag = 1;
			return (lexeme = single_quote_remover(lexeme));
		}
		else if (lexeme[idx] == '"')
			return (lexeme = double_quote_remover(lexeme));
		idx++;
	}
	return (lexeme);
}

static int	open_redir_file(char *pathname, int type, int *fd)
{
	pathname = quote_detector(pathname, 0);
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

static void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

int	manage_redirect(t_tree *tree, int *flag)
{
	int		std_fd[2];
	int		new_fd;
	char	*pathname;

	new_fd = -1;
	if (tree == NULL)
		return (exit_status_holder(EXIT_SUCCESS, 0));
	std_fd[0] = dup(STDIN_FILENO);
	std_fd[1] = dup(STDOUT_FILENO);
	if (is_redirect(tree->type))
	{
		if (tree->left && is_redirect(tree->left->type))
		{
			*flag = *flag + 1;
			manage_redirect(tree->left, flag);
		}
	}
	if (*flag == -1)
	{
		if (dup2(std_fd[0], STDIN_FILENO) == -1)
			return (exit_status_holder(EXIT_FAILURE, true));
		if (dup2(std_fd[1], STDOUT_FILENO) == -1)
			return (exit_status_holder(EXIT_FAILURE, true));
		close_fds(std_fd);
		return (exit_status_holder(EXIT_SUCCESS, 0));
	}
	pathname = ft_strdup(tree->right->command->lexeme);
	if (open_redir_file(pathname, tree->type, &new_fd))
	{
		*flag = -1;
		if (dup2(std_fd[0], STDIN_FILENO) == -1)
			return (exit_status_holder(EXIT_FAILURE, true));
		if (dup2(std_fd[1], STDOUT_FILENO) == -1)
			return (exit_status_holder(EXIT_FAILURE, true));
		close_fds(std_fd);
		return (exit_status_holder(EXIT_FAILURE, 0));
	}
	apply_redirect(tree, &new_fd);
	if (*flag > 0)
	{
		*flag = *flag - 1;
		close_fds(std_fd);
		return (exit_status_holder(EXIT_SUCCESS, 0));
	}
	while (tree->left)
		tree = tree->left;
	if (!is_redirect(tree->type))
		tree_execution(tree, flag);
	if (dup2(std_fd[0], STDIN_FILENO) == -1)
		return (exit_status_holder(EXIT_FAILURE, true));
	if (dup2(std_fd[1], STDOUT_FILENO) == -1)
		return (exit_status_holder(EXIT_FAILURE, true));
	close_fds(std_fd);
	return (exit_status_holder(EXIT_SUCCESS, 0));
}
