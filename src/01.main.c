/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 17:15:26 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*input;

	minishell_init(ac, av, envp);
	while (true)
	{
		is_after_loop(false, false);
		sigquit_activated();
		input = readline(GREEN"<<< Born Again (mini) SHell >>>$ "RESET);
		if (input == NULL)
		{
			control_d_handler();
			return (exit_status_holder(EXIT_SUCCESS, true));
		}
		is_after_loop(true, true);
		if (addto_history_detector(input))
			add_history(input);
		loop_routine(input);
		wait(NULL);
		free(input);
	}
}
