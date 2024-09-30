/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:47:06 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/30 08:50:32 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signals_manager(int sig_nbr)
{
	if (sig_nbr == SIGINT)
		interrupt_signal_runner();
	else if (sig_nbr == SIGQUIT)
		quit_signal_blocker(sig_nbr);
}

void	interrupt_signal_runner(void)
{
	if (child_process_is_running(false, true))
		env_holder(NULL, false, true);
	// if dentro do HereDOC
	//		fechar STDIN
	rl_on_new_line();
	rl_replace_line("", 0);
	ft_putstr_fd("\n", STDOUT_FILENO);
	if (!is_after_loop(false))
		rl_redisplay();
	exit_status_holder(130, true);
}

void	quit_signal_blocker(int sig_nbr)
{
	static sigset_t	sig_tobe_blocked;

	tty_proprieties_manager(true);
	sigemptyset(&sig_tobe_blocked);
	sigaddset(&sig_tobe_blocked, sig_nbr);
	if (sigismember(&sig_tobe_blocked, sig_nbr) == 0)
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

void	signals_init(void)
{
	static struct sigaction	monitor;

	sigemptyset(&monitor.sa_mask);
	monitor.sa_handler = &signals_manager;
	sigaction(SIGINT, &monitor, NULL);
	sigaction(SIGQUIT, &monitor, NULL);
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
