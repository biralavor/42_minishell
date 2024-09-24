/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   48.builtin_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/24 11:24:18 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_exit(t_token_list *lst)
{
	int				exit_code;
	bool			llong_min_status;
	t_token_list	*cmd;

	cmd = lst->next;
	exit_code = 0;
	if (cmd && (cmd->type == WORD || cmd->type == DOUBLE_QUOTES))
	{
		exit_code = exit_error_manager(cmd, exit_code);
		if (cmd->lexeme && exit_code == 0)
			exit_code = exit_valid_code_manager(cmd->lexeme);
	}
	llong_min_status = long_long_min_detected(false, true);
	if (exit_code == 1 && !llong_min_status)
	{
		exit_status_holder(1, true);
		return ;
	}
	if (llong_min_status)
		exit_code = 1;
	clear_all_to_exit_smoothly();
	ft_putendl_fd("exit", STDOUT_FILENO);
	exit(exit_status_holder(exit_code, true));
}

int	exit_error_manager(t_token_list *cmd, int exit_code)
{
	if (cmd->lexeme && cmd->next)
	{
		write(STDERR_FILENO, "bash exit: too many arguments\n", 30);
		exit_code = 1;
	}
	else if (exit_code_not_numeric(cmd->lexeme))
	{
		write(STDERR_FILENO, "bash exit: ", 11);
		write(STDERR_FILENO, cmd->lexeme, ft_strlen(cmd->lexeme));
		write(STDERR_FILENO, ": numeric argument required\n", 28);
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
