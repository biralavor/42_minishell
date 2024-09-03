/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   34.builtins_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/03 16:25:10 by umeneses         ###   ########.fr       */
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
		if (cmd->lexeme && cmd->next->lexeme)
		{
			write(2, "bash exit: too many arguments\n", 30);
			exit_code = 1;
		}
		if (ft_isalpha(cmd->lexeme[0]))
		{
			write(2, "bash exit: ", 11);
			write(2, cmd->lexeme, ft_strlen(cmd->lexeme));
			write(2, ": numeric argument required\n", 28);
			exit_code = 2;
		}
		if (cmd->lexeme)
		{
			exit_code = ft_atoi(cmd->lexeme);
			if (exit_code < 0)
				exit_code = 256 + exit_code;
			else if (exit_code > 255)
				exit_code = exit_code % 256;
		}
	}
	exit(exit_status_holder(exit_code, true));
}

int	exit_status_holder(int actual_exit_status, bool update)
{
	static int	exit_holder;

	if (update)
		exit_holder = actual_exit_status;
	return (exit_holder);
}

void	pid_exit_status_caller(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	if (status == 139)
		status = 1;
	exit_status_holder(status, true);
}
