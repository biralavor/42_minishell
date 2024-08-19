/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25.builtins_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 11:08:16 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_cd(t_token_list *lst)
{
	t_token_list	*cmd;
	int				destiny_len;
	char			*destiny_path;
	char			*actual_path;

	cmd = lst->next;
	destiny_path = NULL;
	actual_path = NULL;
	while (cmd && cmd->type == WORD)
	{
		destiny_path = cmd->lexeme;
		destiny_len = ft_strlen(destiny_path);
		if (chdir(destiny_path) != 0)
			error_cd_messenger(destiny_len, destiny_path);
		else if (destiny_path[0] == '.' && destiny_path[0] == '\0')
			write(2, "\n", 1);
		else
		{
			actual_path = getcwd(actual_path, 100);
			destiny_path = ft_strjoin(actual_path, "/");
			chdir(destiny_path);
		}
		cmd = cmd->next;
	}
}

void	error_cd_messenger(int destiny_len, char *destiny_path)
{
	write(2, "bash: cd: ", 11);
	write(2, destiny_path, destiny_len);
	write(2, ": No such file or directory", 28);
	write(2, "\n", 1);
}
