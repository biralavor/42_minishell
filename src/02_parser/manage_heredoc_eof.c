/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc_eof.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:55:08 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/11 03:43:40 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	eof_del_manager(char *delimiter, int fd)
{
	int		line;
	char	*input;

	line = 0;
	input = NULL;
	while (true)
	{
		is_heredoc_running(true, true);
		input = readline(BLUE"(mini)heredoc<< "RESET);
		line++;
		if (!input)
			break ;
		if (ft_strcmp(delimiter, "\"\""))
		{
			is_heredoc_running(false, false);
			break ;
		}
		dollarsign_heredoc_init(input, fd);
		write(fd, "\n", 1);
		free(input);
	}
	if (!eof_ending_process(input, delimiter, line, fd))
		return (false);
	return (true);
}

bool	eof_ending_process(char *input, char *delimiter, int line, int fd)
{
	if (input == NULL && is_heredoc_running(false, true)
		&& g_sigmonitor != SIGINT)
	{
		heredoc_forcing_exit_warning(input, delimiter, line, fd);
		return (false);
	}
	if (input)
		free(input);
	return (true);
}
