/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   34.builtins_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/29 12:11:02 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins_runner_exit(t_token_list *lst)
{
	int				exit_code;
	t_token_list	*cmd;

	cmd = lst->next;
	exit_code = 0;
	if (cmd && cmd->type == WORD)
	{
		if (ft_isdigit(cmd->lexeme[0]))
		{
			exit_code = ft_atoi(cmd->lexeme);
			if (exit_code < 0)
				exit_code = 256 + exit_code;
			else if (exit_code > 255)
				exit_code = exit_code % 256;
		}
		else
		{
			write(2, "bash exit: ", 11);
			write(2, cmd->lexeme, ft_strlen(cmd->lexeme));
			write(2, ": numeric argument required\n", 28);
			exit_code = 2;
		}
	}
	return (exit_code);
}

int	exit_status_holder(int exit_status)
{
	static int	exit_holder;

	if (WIFEXITED(exit_status))
		exit_holder = WEXITSTATUS(exit_status);
	else if (exit_status != -1)
		exit_holder = exit_status;
	return (exit_holder);
}
