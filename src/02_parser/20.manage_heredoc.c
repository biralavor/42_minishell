/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20.manage_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:23:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 16:31:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_heredoc(t_token_list *lst)
{
	int				hd_fd;
	char			*eof_del;
	t_token_list	*tmp;
	int				original_stdin;

	hd_fd = -1;
	eof_del = NULL;
	tmp = lst;
	original_stdin = dup(STDIN_FILENO);
	while (tmp && tmp->next)
	{
		if (tmp->type == REDIR_HDOC)
		{
			eof_del = redir_quote_detector(ft_strdup(tmp->next->lexeme), 0);
			path_file(lst);
			heredoc_fd_reset(&hd_fd);
			hd_fd = open(tmp->next->lexeme, O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (is_demiliter_null(eof_del) || hd_fd_error_runner(hd_fd)
				|| !check_eof_del(eof_del, hd_fd) || is_signal_sigint(hd_fd))
				break ;
		}
		tmp = tmp->next;
	}
	heredoc_cleanup(hd_fd, original_stdin, eof_del);
}

void	heredoc_cleanup(int hd_fd, int original_stdin, char *eof_del)
{
	heredoc_fd_reset(&hd_fd);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
	if (eof_del)
		free(eof_del);
	is_heredoc_running(false, false);
}

void	path_file(t_token_list *lst)
{
	static int		file_nbr;
	char			*nbr;
	char			*pathname;
	t_token_list	*tmp;

	nbr = ft_itoa(file_nbr);
	pathname = ft_strjoin("/tmp/heredoc_", nbr);
	tmp = lst;
	while (tmp)
	{
		if (tmp->type == REDIR_HDOC)
		{
			free(tmp->next->lexeme);
			tmp->next->lexeme = ft_strdup(pathname);
			break ;
		}
		tmp = tmp->next;
	}
	free(nbr);
	free(pathname);
}

bool	check_eof_del(char *delimiter, int fd)
{
	int		idx;
	int		line;
	char	*input;

	line = 0;
	input = NULL;
	while (true)
	{
		is_heredoc_running(true, true);
		input = readline(BLUE"(mini)heredoc<< "RESET);
		line++;
		idx = 0;
		if (!input)
			break ;
		if (!ft_strcmp(input, delimiter))
		{
			is_heredoc_running(false, false);
			break ;
		}
		while (input && input[idx])
		{
			idx = check_dollar_sign_for_heredoc(input, idx, fd);
			write(fd, &input[idx], 1);
			idx++;
		}
		write(fd, "\n", 1);
		free(input);
	}
	if (input == NULL && is_heredoc_running(false, true) && g_sigmonitor != SIGINT)
	{
		heredoc_forcing_exit_warning(input, delimiter, line, fd);
		return (false);
	}
	else
		exit_status_holder(EXIT_SUCCESS, true);
	if (input)
		free(input);
	free(delimiter);
	return (true);
}

bool	is_heredoc_running(bool update, bool caller)
{
	static bool	heredoc_running;

	if (update && caller)
		heredoc_running = true;
	else if (!update && caller)
		return (heredoc_running);
	else if (!update && !caller)
		heredoc_running = false;
	return (heredoc_running);
}
