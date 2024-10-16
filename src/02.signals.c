/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:47:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 22:11:26 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sigmonitor = 0;

void	signals_manager(bool interactive)
{
	struct sigaction	all_signals;

	all_signals.sa_handler = interrupt_signal_runner;
	sigemptyset(&all_signals.sa_mask);
	all_signals.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &all_signals, NULL) == -1)
		sigaction_error_manager();
	if (interactive)
	{
		all_signals.sa_handler = SIG_IGN;
		sigemptyset(&all_signals.sa_mask);
		all_signals.sa_flags = SA_RESTART;
		if (sigaction(SIGQUIT, &all_signals, NULL) == -1)
			sigaction_error_manager();
	}
	else
		all_signals.sa_handler = SIG_DFL;
	sigemptyset(&all_signals.sa_mask);
	all_signals.sa_flags = SA_RESTART;
	if (sigaction(SIGQUIT, &all_signals, NULL) == -1)
		sigaction_error_manager();
}

void	sigaction_error_manager(void)
{
	perror("sigaction error");
	exit(exit_status_holder(EXIT_FAILURE, true));
}

void	interrupt_signal_runner(int sig)
{
	g_sigmonitor = sig;
	if (child_process_is_running(false, true)
		&& !(isatty(STDIN_FILENO) && isatty(STDOUT_FILENO)))
		env_holder(NULL, false, true);
	if (is_heredoc_running(false, true))
	{
		token_list_holder(NULL, false, true);
		is_heredoc_running(false, false);
		close(STDIN_FILENO);
		// Abrir o dup do stdin original aqui
		/****teste
		 * << a cat (Finaliza com CTRL + C)
		 * << a cat (Finaliza com CTRL + C de novo)
		 */
		close(STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (!is_after_loop(false, true))
		rl_redisplay();
	exit_status_holder(130, true);
}

bool	is_after_loop(bool update, bool caller)
{
	static bool	after_loop;

	if (update && caller)
		after_loop = true;
	else if (!update && caller)
		return (after_loop);
	else if (!update && !caller)
		after_loop = false;
	return (after_loop);
}

void	sigquit_activated(void)
{
	if (exit_status_holder(0, false) == 131)
	{
		ft_putendl_fd(RED" quit (core dumped) T.T"RESET, STDERR_FILENO);
		tty_proprieties_manager(true);
	}
}
