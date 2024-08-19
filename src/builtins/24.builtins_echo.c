/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24.builtins_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 10:44:14 by umeneses         ###   ########.fr       */
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
	if (check_command_args(cmd->lexeme, "-n"))
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

bool	check_command_args(char *lexeme, char *arg)
{
	if (ft_strncmp(lexeme, arg, 2) == 0)
	{
		arg_detector = true;
		return (true);
	}
	return (false);
}
