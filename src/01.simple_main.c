/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.simple_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/11 11:15:51 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char		*input;
	t_env_entry	*env_table;

	if (ac > 1 && av)
	{
		ft_printf(RED"Error: minishell does not accept arguments.\n");
		ft_printf(CYAN"It's a kind of magic, but not that much!\n"RESET);
		exit (EXIT_FAILURE);
	}
	env_table = NULL;
	environment_init(envp, env_table);
	// INIT_SIGNALS
	// get_tty_proprieties
	while (true)
	{
		// set_tty_proprieties
		// sigquit_case() -> Ctrl+/
		input = readline(GREEN"<<< Born Again (mini) SHell >>>$ "RESET);
		if (ft_strncmp(input, "exit", 4) == 0)
			break ;
		add_history(input);
		loop_routine(input);
		wait(NULL);
		free(input);
	}
	rl_clear_history();
	env_holder(env_table, false, true);
	exit(EXIT_SUCCESS);
}
