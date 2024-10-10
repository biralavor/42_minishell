/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20.manage_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:23:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 13:00:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	manage_heredoc(t_token_list *lst)
{
	int				heredoc_fd;
	int				flag;
	char			*delimiter;
	t_token_list	*tmp;
	int				original_stdin;
	
	flag = 0;
	heredoc_fd = -1;
	delimiter = NULL;
	tmp = lst;
	original_stdin = dup(STDIN_FILENO);
	while (tmp && tmp->next)
	{
		if (tmp->type == REDIR_HDOC)
		{
			delimiter = redir_quote_detector(ft_strdup(tmp->next->lexeme), &flag);
			if (delimiter == NULL)
			{
				ft_putendl_fd(" syntax error near unexpected token `newline'", STDERR_FILENO);
				exit_status_holder(2, true);
				break ;
			}
			path_file(lst);
			heredoc_fd_reset(&heredoc_fd);
			heredoc_fd = open(tmp->next->lexeme, O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (heredoc_fd_error_runner(heredoc_fd))
				break ;
			check_delimiter(delimiter, heredoc_fd);
			free(delimiter);
			if (g_sigmonitor == SIGINT)
			{
				dup2(heredoc_fd, STDIN_FILENO);
				break ;
			}
		}
		tmp = tmp->next;
	}
	heredoc_fd_reset(&heredoc_fd);
	dup2(original_stdin, STDIN_FILENO);
	close(original_stdin);
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

int	check_delimiter(char *delimiter, int fd)
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
		heredoc_forcing_exit_warning(input, delimiter, line, fd);
	else
		exit_status_holder(EXIT_SUCCESS, true);
	if (input)
		free(input);
	return (0);
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

void	heredoc_forcing_exit_warning(char *input, char *delimiter, int line, int fd)
{
	char	*line_as_str;

	(void)fd;
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
}
