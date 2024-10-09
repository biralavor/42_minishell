/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:47:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/09 19:56:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sigmonitor = 0;

void	signals_init(bool interactive)
{
	struct sigaction	signal;

	signal.sa_handler = interrupt_signal_runner;
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &signal, NULL) == -1)
	{
		perror("sigaction error");
		exit(exit_status_holder(EXIT_FAILURE, true));
	}
	if (interactive)
	{
		signal.sa_handler = SIG_IGN;
		sigemptyset(&signal.sa_mask);
		signal.sa_flags = SA_RESTART;
		if (sigaction(SIGQUIT, &signal, NULL) == -1)
		{
			perror("sigaction error");
			exit(exit_status_holder(EXIT_FAILURE, true));
		}
	}
	else
	{
		signal.sa_handler = SIG_DFL;
	}
	sigemptyset(&signal.sa_mask);
	signal.sa_flags = SA_RESTART;
	if (sigaction(SIGQUIT, &signal, NULL) == -1)
	{
		perror("sigaction error");
		exit(exit_status_holder(EXIT_FAILURE, true));
	}
}

// void	signals_manager(int sig_nbr)
// {
// 	if (sig_nbr == SIGINT)
// 		interrupt_signal_runner();
// 	else if (sig_nbr == SIGQUIT)
// 		quit_signal_blocker();
// }

void	interrupt_signal_runner(int sig)
{
	g_sigmonitor = sig;
	if (child_process_is_running(false, true))
		env_holder(NULL, false, true);
	if (is_heredoc_running(false, true))
	{
		fprintf(stderr, YELLOW"  interrupt_signal_runner\n");
		fprintf(stderr, YELLOW"g_sigmonitor na interrupt_signal_runner: %d\n"RESET, g_sigmonitor);
		token_list_holder(NULL, false, true);
		close(STDIN_FILENO);
		is_heredoc_running(false, false);
		// close(STDOUT_FILENO);
		// close(STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (!is_after_loop(false))
		rl_redisplay();
	exit_status_holder(130, true);
}

// void	quit_signal_blocker(void)
// {
// 	// static sigset_t			sig_tobe_blocked;
// 	static struct sigaction	monitor_sigquit;

// 	monitor_sigquit.sa_handler = SIG_IGN;
// 	monitor_sigquit.sa_flags = SA_RESTART;
// 	sigemptyset(&monitor_sigquit.sa_mask);
// 	sigaction(SIGQUIT, &monitor_sigquit, NULL);
// 	if (child_process_is_running(false, true))
// 	{
// 		monitor_sigquit.sa_handler = SIG_DFL;
// 		monitor_sigquit.sa_flags = SA_RESTART;
// 		sigemptyset(&monitor_sigquit.sa_mask);
// 		// sigemptyset(&sig_tobe_blocked);
// 		// sigaddset(&sig_tobe_blocked, SIGQUIT);
// 		// if (sigismember(&sig_tobe_blocked, SIGQUIT) == 1)
// 		// 	sigprocmask(SIG_BLOCK, &sig_tobe_blocked, NULL);
// 		// rl_on_new_line();
// 		// if (!is_after_loop(false))
// 		// 	rl_redisplay();
// 		// ft_putendl_fd(RED"^\\quit (core dumped) T.T"RESET, STDERR_FILENO);
// 		// tty_proprieties_manager(true);
// 	}
// 	// rl_replace_line("", 0);
// }

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
