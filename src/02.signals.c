/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:47:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 08:21:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sigmonitor = 0;

void	signals_manager(bool interactive)
{
	struct sigaction	signal;

	signal.sa_handler = interrupt_signal_runner;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &signal, NULL) == -1)
		sigaction_error_manager();
	if (interactive)
	{
		signal.sa_handler = SIG_IGN;
		sigemptyset(&signal.sa_mask);
		signal.sa_flags = SA_RESTART;
		if (sigaction(SIGQUIT, &signal, NULL) == -1)
			sigaction_error_manager();
	}
	else
		signal.sa_handler = SIG_DFL;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	if (sigaction(SIGQUIT, &signal, NULL) == -1)
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
	if (child_process_is_running(false, true))
		env_holder(NULL, false, true);
	if (is_heredoc_running(false, true))
	{
		token_list_holder(NULL, false, true);
		is_heredoc_running(false, false);
		close(STDIN_FILENO);
		close(STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (!is_after_loop(false))
		rl_redisplay();
	exit_status_holder(130, true);
}

bool	is_after_loop(bool update)
{
	static bool	after_loop;

	if (update)
		after_loop = true;
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
