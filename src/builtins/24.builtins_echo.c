/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24.builtins_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 11:30:00 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	arg_detector;

void	builtins_runner_echo(t_token_list *lst)
{
	t_token_list	*cmd;

	cmd = lst->next;
	if (NULL == cmd)
	{
		write(1, "\n", 1);
		return ;
	}
	if (checking_cmd_arg_options(cmd->lexeme, "-n"))
		cmd = cmd->next;
	while (cmd)
	{
		ft_putstr_fd(cmd->lexeme, STDOUT_FILENO);
		if (NULL == cmd->next)
			break ;
		else
			ft_putstr_fd(" ", STDOUT_FILENO);
		cmd = cmd->next;
	}
	if (!arg_detector)
		write(1, "\n", 1);
}
