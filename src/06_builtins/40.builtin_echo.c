/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   40.builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/18 14:54:45 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_echo(t_token_list *lst, bool arg_option)
{
	short int		space;
	t_token_list	*cmd;

	cmd = lst->next;
	space = 0;
	if (NULL == cmd)
	{
		write(STDOUT_FILENO, "\n", 1);
		return ;
	}
	if (checking_cmd_arg_options(cmd->lexeme, "-n"))
		cmd = cmd->next;
	while (cmd)
	{
		if (space)
			ft_putstr_fd(" ", STDOUT_FILENO);
		else
			space++;
		ft_putstr_fd(cmd->lexeme, STDOUT_FILENO);
		if (NULL == cmd->next)
			break ;
		cmd = cmd->next;
	}
	arg_option = arg_option_holder(false, true);
	if (!arg_option)
		write(STDOUT_FILENO, "\n", 1);
	exit_status_holder(0, true);
}
