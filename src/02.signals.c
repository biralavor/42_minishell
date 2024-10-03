/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:47:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/03 09:38:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_sigmonitor = 0;

void	signals_init(void)
{
	static struct sigaction	monitor_sigint;
	static struct sigaction	monitor_sigquit;

	monitor_sigint.sa_handler = &signals_manager;
	monitor_sigint.sa_flags = 0;
	sigemptyset(&monitor_sigint.sa_mask);
	sigaction(SIGINT, &monitor_sigint, NULL);
	// sigprocmask(SIG_BLOCK, &sig_tobe_blocked, NULL);
	monitor_sigquit.sa_handler = &signals_manager;
	monitor_sigquit.sa_flags = 0;
	sigemptyset(&monitor_sigquit.sa_mask);
	sigaction(SIGQUIT, &monitor_sigquit, NULL);
}

void	signals_manager(int sig_nbr)
{
	if (sig_nbr == SIGINT)
		interrupt_signal_runner();
	else if (sig_nbr == SIGQUIT)
		quit_signal_blocker();
}

void	interrupt_signal_runner(void)
{
	if (child_process_is_running(false, true))
		env_holder(NULL, false, true);
	if (is_heredoc_running(false, true))
		close(STDIN_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	ft_putstr_fd("\n", STDOUT_FILENO);
	if (!is_after_loop(false))
		rl_redisplay();
	exit_status_holder(130, true);
}

void	quit_signal_blocker(void)
{
	static sigset_t	sig_tobe_blocked;

	tty_proprieties_manager(true);
	
	sigemptyset(&sig_tobe_blocked);
	sigaddset(&sig_tobe_blocked, SIGQUIT);
	if (sigismember(&sig_tobe_blocked, SIGQUIT) == 0)
		sigprocmask(SIG_BLOCK, &sig_tobe_blocked, NULL);
	else
		fprintf(stderr, ">>>>>>>>>> erro no sig sigprocmask");
	// rl_on_new_line();
	rl_replace_line("", 0);
	if (!is_after_loop(false))
		rl_redisplay();
}

void	quit_signal_unblocker(int sig_nbr)
{
	sigset_t	sig_tobe_released;

	tty_proprieties_manager(true);
	sigemptyset(&sig_tobe_released);
	sigaddset(&sig_tobe_released, sig_nbr);
	sigprocmask(SIG_UNBLOCK, &sig_tobe_released, NULL);
	exit_status_holder(131, true);
}

void	tty_proprieties_manager(bool update)
{
	static struct termios	terminal;

	if (update)
		tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
	else
		tcgetattr(STDIN_FILENO, &terminal);
}

bool	is_after_loop(bool update)
{
	static bool	after_loop;

	if (update)
		after_loop = true;
	return (after_loop);
}
