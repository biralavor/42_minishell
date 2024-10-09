/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_proprieties.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:42:33 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/08 22:48:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tty_proprieties_manager(bool restore)
{
	static struct termios	terminal;

	if (restore)
		tcsetattr(STDIN_FILENO, TCSANOW, &terminal);
	else
		tcgetattr(STDIN_FILENO, &terminal);
}

bool	is_interactive(void)
{
	if (isatty(STDIN_FILENO))
		return (true);
	return (false);
}
