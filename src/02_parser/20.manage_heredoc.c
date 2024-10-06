/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20.manage_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:23:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/04 23:11:00 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
static int	check_fd_error(int heredoc_fd);
static int	check_dollar_sign(char *input, int idx, int fd);
static int	check_question_mark(int idx, int fd);

void	check_heredoc(t_token_list *lst)
{
	int				heredoc_fd;
	int				flag;
	char			*heredoc_input;
	char			*delimiter;
	t_token_list	*tmp;
	int				line;

	line = 0;
	flag = 0;
	heredoc_fd = -1;
	heredoc_input = NULL;
	delimiter = NULL;
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->type == REDIR_HDOC)
		{
			delimiter = redir_quote_detector(ft_strdup(tmp->next->lexeme), &flag);
			path_file(lst);
			heredoc_fd_reset(&heredoc_fd);
			heredoc_fd = open(tmp->next->lexeme, O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (check_fd_error(heredoc_fd))
				break;
			is_heredoc_running(true, true);
			heredoc_input = readline(BLUE"(mini)heredoc> "RESET);
			line++;
			if (g_sigmonitor == SIGINT)
			{
				free(heredoc_input);
				return ;
			}
			if (heredoc_input == NULL)
			{
				heredoc_forcing_exit_warning(heredoc_input, delimiter, line, heredoc_fd);
				free_token_list(&tmp);
			}
			if (!check_delimiter(delimiter, heredoc_fd, heredoc_input, line))
				break ;
		}
		tmp = tmp->next;
	}
	heredoc_fd_reset(&heredoc_fd);
	is_heredoc_running(false, false);
	if (delimiter != NULL)
		free(delimiter);
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
			tmp->next->type = ARCHIVE;
			free(tmp->next->lexeme);
			tmp->next->lexeme = ft_strdup(pathname);
		}
		tmp = tmp->next;
	}
	free(nbr);
	free(pathname);
}

int	check_delimiter(char *delimiter, int fd, char *input, int line)
{
	int	idx;

	idx = 0;
	while (input && ft_strncmp(input, delimiter, (ft_strlen(delimiter) - 1)))
	{
		while (input[idx])
		{
			idx = check_dollar_sign(input, idx, fd);
			write(fd, &input[idx], 1);
			idx++;
		}
		// 	write(fd, "\n", 1);
		free(input);
		is_heredoc_running(true, true);
		input = readline(BLUE"(mini)heredoc> "RESET);
		line++;
		if (g_sigmonitor == SIGINT)
		{
			free(input);
			return (1);
		}
		heredoc_forcing_exit_warning(input, delimiter, line, fd);
	}
	if (input)
		free(input);
	return (0);
}

static int	check_dollar_sign(char *input, int idx, int fd)
{
	size_t	start;
	size_t	end;
	char	*var;

	start = idx;
	end = 0;
	var = NULL;
	if (input[idx] == '$' && (input[idx + 1] && input[idx + 1] != '?'))
	{
		while (input[idx] && !is_blank(input[idx]))
			idx++;
		end = (size_t)idx;
		var = expansion_env_var_runner((ft_substr(input, start, (end - start))), 0);
		idx = 0;
		while (var[idx])
		{
			write(fd, &var[idx], 1);
			idx++;
		}
		return (end);
		free(var);
	}
	else if (input[idx] == '$' && (input[idx + 1] && input[idx + 1] == '?'))
		idx = check_question_mark(idx, fd);
	return (idx);
}

static int	check_question_mark(int idx, int fd)
{
	int		idx_exit_status;
	char	*exit_status;

	idx_exit_status = 0;
	exit_status = ft_itoa(exit_status_holder(0, false));
	while (exit_status[idx_exit_status])
	{
		write(fd, &exit_status[idx_exit_status], 1);
		idx_exit_status++;
	}
	return (idx + 2);
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

void	heredoc_fd_reset(int *heredoc_fd)
{
	if (*heredoc_fd != -1)
	{
		close(*heredoc_fd);
		*heredoc_fd = -1;
	}
}

static int	check_fd_error(int heredoc_fd)
{
	if (heredoc_fd == -1)
	{
		ft_putendl_fd("Failed to open heredoc file\n", STDERR_FILENO);
		exit_status_holder(EXIT_FAILURE, true);
		return (1);
	}
	return (0);
}

void	heredoc_forcing_exit_warning(char *input, char *delimiter, int line, int fd)
{
	char	*line_as_str;

	line_as_str = ft_itoa(line);
	ft_putstr_fd(" here-document at line ", STDERR_FILENO);
	ft_putstr_fd(line_as_str, STDERR_FILENO);
	ft_putstr_fd(" delimited by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(delimiter, STDERR_FILENO);
	ft_putendl_fd("')", STDERR_FILENO);
	env_holder(NULL, false, true);
	close(fd);
	free(input);
	free(line_as_str);
	free(delimiter);
	exit(exit_status_holder(EXIT_SUCCESS, true));
}
