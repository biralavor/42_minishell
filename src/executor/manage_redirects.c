/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:20:13 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/11 10:57:12 by tmalheir         ###   ########.fr       */
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
		printf("TO RECLAMANDO, NÃO ACHEI O ARQUIVO %s\n", pathname); // Alterar mensagem de erro
	free(pathname);
	return (*fd);
}

int	manage_redirect(t_tree *tree, int flag)
{
	int				std_fd[2];
	int				new_fd;
	int				ret_code = 0;
	static int		first_in;
	static int		first_out;

	new_fd = 0;
	if (!flag)
	{
		first_in = 0;
		first_out = 0;
	}
	if (open_redir_file(tree, &new_fd) != -1)
	{
		std_fd[0] = dup(STDIN_FILENO);
		std_fd[1] = dup(STDOUT_FILENO);
		if (tree->right && !tree->right->right)
		{
			if (tree->type == REDIR_IN && !first_in)
			{
				first_in = 1;
				apply_redirect(tree, &new_fd);
			}
			else if ((tree->type == REDIR_OUT || tree->type == REDIR_OUTAPP) && !first_out)
			{
				first_out = 1;
				apply_redirect(tree, &new_fd);
			}
		}
		if (tree->left)
			ret_code = tree_execution(tree->left, 1);
		dup2(std_fd[0], STDIN_FILENO);
		dup2(std_fd[1], STDOUT_FILENO);
		close(std_fd[0]);
		close(std_fd[1]);
		return (ret_code);
	}
	return (-1); // O programa deve sair nesse caso?

}
