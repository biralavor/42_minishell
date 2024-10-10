/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:56:22 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 15:28:01 by umeneses         ###   ########.fr       */
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

bool	hd_fd_error_runner(int heredoc_fd)
{
	if (heredoc_fd == -1)
	{
		ft_putendl_fd("Failed to open heredoc file\n", STDERR_FILENO);
		exit_status_holder(EXIT_FAILURE, true);
		return (true);
	}
	return (false);
}

bool	is_demiliter_null(char *delimiter)
{
	if (delimiter == NULL)
	{
		ft_putendl_fd(" syntax error near unexpected token `newline'", STDERR_FILENO);
		exit_status_holder(2, true);
		return (true);
	}
	return (false);
}

bool	is_signal_sigint(int heredoc_fd)
{
	if (g_sigmonitor == SIGINT)
	{
		dup2(heredoc_fd, STDIN_FILENO);
		return (true);
	}
	return (false);
}

void	heredoc_forcing_exit_warning(char *input, char *delimiter, int line, int fd)
{
	char	*line_as_str;

	(void)fd;
	is_heredoc_running(false, false);
	line_as_str = ft_itoa(line);
	ft_putstr_fd(" here-document at line ", STDERR_FILENO);
	ft_putstr_fd(line_as_str, STDERR_FILENO);
	ft_putstr_fd(" delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(delimiter, STDERR_FILENO);
	ft_putendl_fd("')", STDERR_FILENO);
	env_holder(NULL, false, true);
	free(input);
	free(line_as_str);
	exit_status_holder(EXIT_SUCCESS, true);
	g_sigmonitor = SIGUSR1;
}
