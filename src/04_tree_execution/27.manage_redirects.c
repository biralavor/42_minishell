/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.manage_redirects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:20:13 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/24 12:21:07 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	apply_redirect(t_tree *tree, int *fd)
{
	if (tree->type == REDIR_IN || tree->type == REDIR_HDOC)
	{
		if (dup2(*fd, STDIN_FILENO) == -1)
		exit(exit_status_holder(EXIT_FAILURE, true));
		close(*fd);
	}
	if (tree->type == REDIR_OUT || tree->type == REDIR_OUTAPP)
	{
		if (dup2(*fd, STDOUT_FILENO) == -1)
		exit(exit_status_holder(EXIT_FAILURE, true));
		close(*fd);
	}
}

static void	check_if_apply_redirect(t_tree *tree, int *first_redir, int new_fd)
{
	if ((tree->type == REDIR_IN || tree->type == REDIR_HDOC)&& !first_redir[0])
	{
		first_redir[0] = 1;
		apply_redirect(tree, &new_fd);
	}
	else if (is_redir_out(tree->type) && !first_redir[1])
	{
		first_redir[1] = 1;
		apply_redirect(tree, &new_fd);
	}
}

/**
 * @todo change error message in *fd < 0 condition
 * and make it return to the loop routine
 */
static int	open_redir_file(t_tree *tree, int *fd)
{
	char	*pathname;

	pathname = ft_strdup(tree->right->command->lexeme);
	if (tree->type == REDIR_IN || tree->type == REDIR_HDOC)
		*fd = open(pathname, O_RDONLY);
	else if (tree->type == REDIR_OUT)
		*fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (tree->type == REDIR_OUTAPP)
		*fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*fd < 0)
	{
		ft_putendl_fd(" No such file or directory", STDERR_FILENO);
		exit_status_holder(EXIT_FAILURE, true);
		// printf("TO RECLAMANDO, NÃO ACHEI O ARQUIVO %s\n", pathname);
	}
	free(pathname);
	return (*fd);
}

/**
 * @todo check if function has the right lines number when ret_code is removed
 */
void	manage_redirect(t_tree *tree, int flag)
{
	int				std_fd[2];
	int				new_fd;
	static int		first_redir[2];

	new_fd = -1;
	if (!flag)
		change_redir_flag(first_redir);
	open_redir_file(tree, &new_fd);
	std_fd[0] = dup(STDIN_FILENO);
	std_fd[1] = dup(STDOUT_FILENO);
	if (tree->right && !tree->right->right)
		check_if_apply_redirect(tree, first_redir, new_fd);
	if (tree->left)
		tree_execution(tree->left, 1);
	if (dup2(std_fd[0], STDIN_FILENO) == -1)
		exit(exit_status_holder(EXIT_FAILURE, true));
	if (dup2(std_fd[1], STDOUT_FILENO) == -1)
		exit(exit_status_holder(EXIT_FAILURE, true));
	close(std_fd[0]);
	close(std_fd[1]);
}
