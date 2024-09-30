/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20.manage_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:23:53 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/30 14:48:17 by tmalheir         ###   ########.fr       */
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
//			tmp->next->lexeme = ft_strdup(path_file());
			heredoc_fd = open(tmp->next->lexeme, O_CREAT | O_RDWR | O_TRUNC, 0644);
			heredoc_input = readline(">");
			if (!check_delimiter(delimiter, heredoc_fd, heredoc_input))
				break ;
		}
		tmp = tmp->next;
	}
	if (heredoc_fd != -1)
		close(heredoc_fd);
	if (delimiter != NULL)
		free(delimiter);
	if (heredoc_input != NULL)
		free(heredoc_input);
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
			tmp->next->lexeme = ft_strdup(pathname);
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
		input = readline(">");
	}
	if (input)
		free(input);
	return (0);
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