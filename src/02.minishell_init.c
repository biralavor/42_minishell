/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.minishell_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 08:02:42 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 18:25:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	extra_args(void);

void	minishell_init(int ac, char **av, char **envp)
{
	if (ac > 1 && av)
		extra_args();
	signals_manager(is_interactive());
	tty_proprieties_manager(false);
	environment_init(envp);
}

static void	extra_args(void)
{
	ft_printf(RED"Error: minishell does not accept arguments.\n");
	ft_printf(CYAN"It's a kind of magic, but not that much!\n"RESET);
	exit (EXIT_FAILURE);
}

void	control_d_handler(void)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	env_holder(NULL, false, true);
	if (g_sigmonitor == SIGUSR1)
	{
		token_list_holder(NULL, false, true);
		tree_holder(NULL, true);
		g_sigmonitor = 0;
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
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
