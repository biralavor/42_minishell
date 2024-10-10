/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:54:18 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/09 21:09:54 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_dollar_sign_for_heredoc(char *input, int idx, int fd)
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
		idx = check_question_mark_for_heredoc(idx, fd);
	return (idx);
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
