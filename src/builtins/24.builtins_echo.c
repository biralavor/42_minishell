/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24.builtins_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/03 12:34:01 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_echo(t_token_list *lst, bool arg_option)
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
	arg_option = arg_option_holder(false, true);
	if (!arg_option)
		write(1, "\n", 1);
	exit_status_holder(0, true);
}
