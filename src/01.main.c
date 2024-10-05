/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/01 11:42:04 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	extra_args(void)
{
	ft_printf(RED"Error: minishell does not accept arguments.\n");
	ft_printf(CYAN"It's a kind of magic, but not that much!\n"RESET);
	exit (EXIT_FAILURE);
}

void	control_d_handler(char *input)
{
	if (input == NULL)
	{
		ft_putendl_fd("exit", STDOUT_FILENO);
		env_holder(NULL, false, true);
		free(input);
		exit(exit_status_holder(0, true));
	}
}

bool	addto_history_detector(const char *input)
{
	int	idx;

	idx = 0;
	if (!ft_strcmp(input, ""))
		return (false);
	else
	{
		while (input[idx])
		{
			if (input[idx] != 32)
				return (true);
			idx++;
		}
	}
	return (false);
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
		control_d_handler(input);
		is_after_loop(true);
		if (addto_history_detector(input))
			add_history(input);
		loop_routine(input);
		wait(NULL);
		free(input);
	}
}
