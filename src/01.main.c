/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/30 18:12:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	extra_args(void)
{
	ft_printf(RED"Error: minishell does not accept arguments.\n");
	ft_printf(CYAN"It's a kind of magic, but not that much!\n"RESET);
	exit (EXIT_FAILURE);
}

int	main(int ac, char **av, char **envp)
{
	char	*input;

	if (ac > 1 && av)
		extra_args();
	signals_init();
	tty_proprieties_manager(false);
	environment_init(envp);
	while (true)
	{
		is_after_loop(false);
		signals_manager(g_sigmonitor);
		// sigquit_case() -> Ctrl+/
		input = readline(GREEN"<<< Born Again (mini) SHell >>>$ "RESET);
		is_after_loop(true);
		add_history(input);
		loop_routine(input);
		wait(NULL);
		free(input);
	}
}
