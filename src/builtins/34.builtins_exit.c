/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   34.builtins_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/04 11:11:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_exit(t_token_list *lst)
{
	int				exit_code;
	t_token_list	*cmd;

	cmd = lst->next;
	exit_code = 0;
	if (cmd && cmd->type == WORD)
	{
		exit_code = exit_error_manager(cmd, exit_code);
		if (cmd->lexeme && exit_code == 0)
		{
			exit_code = ft_atoi(cmd->lexeme);
			if (exit_code < 0)
				exit_code = 256 + exit_code;
			else if (exit_code > 255)
				exit_code = exit_code % 256;
		}
	}
	if (exit_code == 1)
	{
		exit_status_holder(1, true);
		return ;
	}
	else
	{
		clear_all_to_exit_smoothly();
		exit(exit_status_holder(exit_code, true));
	}
}

int	exit_error_manager(t_token_list *cmd, int exit_code)
{
	if (cmd->lexeme && cmd->next)
	{
		write(2, "bash exit: too many arguments\n", 30);
		exit_code = 1;
	}
	else if (ft_isalpha(cmd->lexeme[0]))
	{
		write(2, "bash exit: ", 11);
		write(2, cmd->lexeme, ft_strlen(cmd->lexeme));
		write(2, ": numeric argument required\n", 28);
		exit_code = 2;
	}
	return (exit_code);
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

void	clear_all_to_exit_smoothly(void)
{
	rl_clear_history();
	env_holder(NULL, false, true);
	tree_holder(NULL, true);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}
