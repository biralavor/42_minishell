/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24.builtins_echo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/18 14:39:25 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_echo(char **cmd)
{
	int	idx;

	idx = 1;
	if (cmd[idx + 1] == NULL)
		write(1, "\n", 1);
	else
	{
		if (check_command_args(cmd, "-n"))
			idx++;
		while (cmd[idx] != NULL)
		{
			ft_putstr_fd(cmd[idx], STDOUT_FILENO);
			if (NULL == cmd[idx + 1])
				break ;
			else
				ft_putstr_fd(" ", STDOUT_FILENO);
			idx++;
		}
		if (!check_command_args(cmd, "-n"))
			write(1, "\n", 1);
	}
}

bool	check_command_args(char **cmd, char *arg)
{
	int		idx;

	idx = 1;
	if (ft_strncmp(cmd[idx], arg, 2) == 0)
		return (true);
	return (false);
}
