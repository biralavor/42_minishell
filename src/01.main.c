/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/06 23:32:53 by umeneses         ###   ########.fr       */
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

bool	is_interactive(void)
{
	if (isatty(STDIN_FILENO))
		return (true);
	return (false);
}

void	sigquit_activated(void)
{
	if (exit_status_holder(0, false) == 131)
	{
		ft_putendl_fd(RED"^\\quit (core dumped) T.T"RESET, STDERR_FILENO);
		tty_proprieties_manager(true);
	}
}

bool	is_interactive(void)
{
	if (isatty(STDIN_FILENO))
		return (true);
	return (false);
}

void	sigquit_activated(void)
{
	if (exit_status_holder(0, false) == 131)
	{
		ft_putendl_fd(RED"^\\quit (core dumped) T.T"RESET, STDERR_FILENO);
		tty_proprieties_manager(true);
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

bool	is_interactive(void)
{
	if (isatty(STDIN_FILENO))
		return (true);
	return (false);
}

void	sigquit_activated(void)
{
	if (exit_status_holder(0, false) == 131)
	{
		ft_putendl_fd(RED"^\\quit (core dumped) T.T"RESET, STDERR_FILENO);
		tty_proprieties_manager(true);
	}
}

int	main(int ac, char **av, char **envp)
{
	char	*input;

	if (ac > 1 && av)
		extra_args();
	signals_init(is_interactive());
	tty_proprieties_manager(false);
	environment_init(envp);
	// signals_manager(g_sigmonitor);
	while (true)
	{
		is_after_loop(false);
		sigquit_activated();
		// fprintf(stderr, BLUE"exit_status: %d\n"RESET, exit_status_holder(0, false));
		// fprintf(stderr, YELLOW"g_sigmonitor na main: %d\n"RESET, g_sigmonitor);
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
