/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_fds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:56:22 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/09 20:57:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_fd_reset(int *heredoc_fd)
{
	if (*heredoc_fd != -1)
	{
		close(*heredoc_fd);
		*heredoc_fd = -1;
	}
}

int	heredoc_fd_error_runner(int heredoc_fd)
{
	if (heredoc_fd == -1)
	{
		ft_putendl_fd("Failed to open heredoc file\n", STDERR_FILENO);
		exit_status_holder(EXIT_FAILURE, true);
		return (1);
	}
	return (0);
}
