/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24.tree_execution_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:37:28 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/10 20:26:59 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fork_error(void)
{
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	return (exit_status_holder(EXIT_FAILURE, true));
}

bool	is_redir_out(int type)
{
	if (type == REDIR_OUT || type == REDIR_OUTAPP)
		return (true);
	return (false);
}

void	change_redir_flag(int *first_redir)
{
	first_redir[0] = 0;
	first_redir[1] = 0;
}
