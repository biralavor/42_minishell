/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:54:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/11 03:59:40 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollarsign_heredoc_init(char *input, int fd)
{
	int	idx;

	idx = 0;
	while (input && input[idx])
	{
		idx = dollarsign_for_heredoc_manager(input, idx, fd);
		if (input[idx])
			write(fd, &input[idx++], 1);
	}
}

int	dollarsign_for_heredoc_manager(char *input, int idx, int fd)
{
	size_t	start;

	start = idx;
	if (input[idx] == '$' && (input[idx + 1] && input[idx + 1] != '?'))
	{
		idx = dollarsign_for_heredoc_runner(input, idx + 1, start, fd);
	}
	else if (input[idx] == '$' && (input[idx + 1] && input[idx + 1] == '?'))
		idx = check_question_mark_for_heredoc(idx, fd);
	return (idx);
}

int	dollarsign_for_heredoc_runner(char *input, int idx, size_t start, int fd)
{
	char	*var;
	size_t	end;

	var = NULL;
	end = 0;
	while (input[idx] && !is_blank(input[idx]))
		idx++;
	end = (size_t)idx;
	var = expansion_env_var_manager((ft_substr(input, start,
					(end - start))), 0);
	idx = 0;
	while (var[idx])
	{
		write(fd, &var[idx], 1);
		idx++;
	}
	free(var);
	return (end);
}

int	check_question_mark_for_heredoc(int idx, int fd)
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
