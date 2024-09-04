/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:20:13 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/04 16:40:02 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @todo Implement heredoc
 */

bool	is_redirect(int lst_type)
{
	if (lst_type == REDIR_IN || lst_type == REDIR_HDOC
		|| lst_type == REDIR_OUT || lst_type == REDIR_OUTAPP)
		return (true);
	return (false);
}

static void	apply_redirect(t_tree *tree, int *fd)
{
	if (tree->type == REDIR_IN || tree->type == REDIR_HDOC)
	{
		dup2(*fd, STDIN_FILENO);
		close(*fd);
//		exit(EXIT_SUCCESS);
	}
	if (tree->type == REDIR_OUT || tree->type == REDIR_OUTAPP)
	{
		dup2(*fd, STDOUT_FILENO);
		close(*fd);
//		exit(EXIT_SUCCESS);
	}
}
static int	open_redir_file(t_tree *tree, int *fd, int flag)
{
	char	*pathname;

	if (flag == 0)
		pathname = tree->left->command->lexeme;
	if (flag == 1)
		pathname = tree->right->command->lexeme;
	if (tree && (tree->type == REDIR_IN))
		*fd = open(pathname, O_RDONLY);
	else if (tree && tree->type == REDIR_OUT)
		*fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (tree->type == REDIR_OUTAPP)
		*fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (tree && tree->right && !tree->right->right && flag == 0)
		*fd = open_redir_file(tree, fd, 1);
	return (*fd);
}

int	manage_redirect(t_tree *tree)
{
	int				std_fd[2];
	int				new_fd;
	static t_tree	*command;

	new_fd = 0;
	if (tree->left->type == WORD || tree->left->type == DOUBLE_QUOTES
		|| tree->left->type == SINGLE_QUOTES || tree->left->type == SUBSHELL)
		command = tree->left;
	if (open_redir_file(tree, &new_fd, 0) != -1)
	{
		std_fd[0] = dup(STDIN_FILENO);
		std_fd[1] = dup(STDOUT_FILENO);
		apply_redirect(tree, &new_fd);
		if (tree->right && !tree->right->right)
			tree_execution(command);
		else if (tree->right)
			tree_execution(tree->right);
		dup2(std_fd[0], STDIN_FILENO);
		dup2(std_fd[1], STDOUT_FILENO);
		close(std_fd[0]);
		close(std_fd[1]);
		return (0);
	}
	return (-1); // O programa deve sair nesse caso?
}