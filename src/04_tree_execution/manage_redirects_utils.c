/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_redirects_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:06:38 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/01 10:28:07 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_left_redirect(t_tree *tree, int *flag)
{
	if (tree->left && is_redirect(tree->left->type))
	{
		(*flag)++;
		manage_redirect(tree->left, flag);
	}
}

void	restore_standard_fds(int *std_fd)
{
	if (dup2(std_fd[0], STDIN_FILENO) == -1)
		exit_status_holder(EXIT_FAILURE, true);
	if (dup2(std_fd[1], STDOUT_FILENO) == -1)
		exit_status_holder(EXIT_FAILURE, true);
	close_fds(std_fd);
}

void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	decrement_flag_and_close_fds(int *flag, int *std_fd)
{
	if (*flag > 0)
	{
		(*flag)--;
		close_fds(std_fd);
		return ;
	}
}

char	*redir_quote_detector(char *lexeme, int *flag)
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
