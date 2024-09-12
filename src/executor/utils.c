/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:37:28 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/11 15:15:37 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fork_error(void)
{
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	return (-1);
}

bool	is_redirect(int lst_type)
{
	if (lst_type == REDIR_IN || lst_type == REDIR_HDOC
		|| lst_type == REDIR_OUT || lst_type == REDIR_OUTAPP)
		return (true);
	return (false);
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
