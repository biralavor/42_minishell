/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.simple_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/12 10:38:37 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*input;

	if (ac > 1 && av)
	{
		ft_printf(RED"Error: minishell does not accept arguments.\n");
		ft_printf(CYAN"It's a kind of magic, but not that much!\n"RESET);
		exit (EXIT_FAILURE);
	}
	environment_init(envp);
	// INIT_SIGNALS
	// get_tty_proprieties
	while (true)
	{
		// set_tty_proprieties
		// sigquit_case() -> Ctrl+/
		input = readline(GREEN"<<< Born Again (mini) SHell >>>$ "RESET);
		add_history(input);
		loop_routine(input);
		wait(NULL);
		free(input);
	}
	rl_clear_history();
	env_holder(NULL, false, true);
	exit(EXIT_SUCCESS);
}
