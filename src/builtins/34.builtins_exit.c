/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   34.builtins_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 17:48:55 by umeneses         ###   ########.fr       */
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

int	exit_status_holder(int code, bool update, bool call_status)
{
	static int	exit_status;

	if (update && call_status)
		exit_status = code;
	if (!update && call_status)
		return (exit_status);
	return (exit_status);
}