/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20.manage_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:23:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/01 11:35:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_heredoc(t_token_list *lst)
{
	int				heredoc_fd;
	char			*heredoc_input;
	char			*delimiter;
	t_token_list	*tmp;

	heredoc_fd = -1;
	heredoc_input = NULL;
	delimiter = NULL;
	tmp = lst;
	while (tmp->next)
	{
		if (tmp->type == REDIR_HDOC)
		{
			delimiter = ft_strdup(tmp->next->lexeme);
			path_file(lst);
			heredoc_fd_reset(&heredoc_fd);
			heredoc_fd = open(tmp->next->lexeme, O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (heredoc_fd == -1)
			{
				ft_putendl_fd("Failed to open heredoc file\n", STDERR_FILENO);
				exit_status_holder(EXIT_FAILURE, true);
				break ;
			}
			heredoc_input = readline(BLUE"(mini)heredoc> "RESET);
			if (!check_delimiter(delimiter, heredoc_fd, heredoc_input))
				break ;
		}
		tmp = tmp->next;
	}
	heredoc_fd_reset(&heredoc_fd);
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
			is_heredoc_running(true, false);
		}
		tmp = tmp->next;
	}
	free(nbr);
	free(pathname);
}

int	check_delimiter(char *delimiter, int fd, char *input)
{
	while (input && ft_strncmp(input, delimiter, (ft_strlen(delimiter) - 1)))
	{
		if (input)
		{
			write(fd, input, ft_strlen(input));
			write(fd, "\n", 1);
		}
		is_heredoc_running(true, false);
		free(input);
		input = readline(BLUE"(mini)heredoc> "RESET);
	}
	if (input)
		free(input);
	return (0);
}

bool	is_heredoc_running(bool update, bool caller)
{
	static bool	heredoc_running;

	if (update && !caller)
		heredoc_running = update;
	else if (!update && caller)
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


/*
static char	*path_file(void)
{
	static int	file_nbr;
	char		*nbr;
	char		*heredoc_path;

	nbr = ft_itoa(file_nbr);
	heredoc_path = ft_strjoin("/tmp/heredoc_", nbr);
	free(nbr);
	return (heredoc_path);
}
*/