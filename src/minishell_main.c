/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:53:12 by umeneses          #+#    #+#             */
/*   Updated: 2024/06/12 15:42:41 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	char	**cmd;
	char	*path;
	pid_t	pid;

	cmd = NULL;
	path = NULL;
	ft_printf("Welcome to Minishell\n");
	while (1)
	{
		input = readline(GREEN"Minishell: "RESET);
		if (ft_strncmp(input, "exit", 4) == 0)
			break ;
		pid = fork();
		if (!pid)
		{
			cmd = ft_split(input, ' ');
			path = ft_strjoin("/usr/bin/", cmd[0]);
			execve(path, cmd, __environ);
			printf(RED"Error: %s\n"RESET, strerror(errno));
			free (cmd);
			exit(0);
		}
		else
			waitpid(pid, NULL, 0);
	}
	free (input);
	return (0);
}
