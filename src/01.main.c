/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/23 13:42:59 by tmalheir         ###   ########.fr       */
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
	// INIT_SIGNALS
	// get_tty_proprieties
	environment_init(envp);
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
}
