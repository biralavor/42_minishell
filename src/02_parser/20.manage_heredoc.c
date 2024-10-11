/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20.manage_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:23:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/11 03:38:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_heredoc(t_token_list *lst)
{
	int				hd_fd;
	char			*eof_del;
	t_token_list	*tmp;

	hd_fd = -1;
	eof_del = NULL;
	tmp = lst;
	original_stdin_holder(STDIN_FILENO, true, false);
	while (tmp && tmp->next)
	{
		if (tmp->type == REDIR_HDOC)
		{
			eof_del = redir_quote_detector(ft_strdup(tmp->next->lexeme), 0);
			if (ft_strcmp(tmp->next->lexeme, "\"\"") == 0)
			{
				eof_del = ft_strdup("\"\"");
				// ft_putendl_fd("bash: warning: here-document at line X delimited by an empty string", STDERR_FILENO);
				// heredoc_cleanup(hd_fd, original_stdin_holder(0, false, false), eof_del);
				// return;
			}
			path_file(lst);
			heredoc_fd_reset(&hd_fd);
			hd_fd = open(tmp->next->lexeme, O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (is_demiliter_null(eof_del) || hd_fd_error_runner(hd_fd)
				|| !eof_del_manager(eof_del, hd_fd) || is_signal_sigint(hd_fd))
				break ;
		}
		tmp = tmp->next;
	}
	heredoc_cleanup(hd_fd, original_stdin_holder(0, false, false), eof_del);
}

int	original_stdin_holder(int fd, bool update, bool restore)
{
	static int	original_stdin_holder = 0;

	if (update)
		original_stdin_holder = dup(fd);
	else if (restore)
		original_stdin_holder = dup2(original_stdin_holder, STDIN_FILENO);
	return (original_stdin_holder);
}

void	heredoc_cleanup(int hd_fd, int original_stdin, char *eof_del)
{
	heredoc_fd_reset(&hd_fd);
	original_stdin_holder(original_stdin, false, true);
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
