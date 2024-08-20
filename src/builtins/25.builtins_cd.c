/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25.builtins_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/20 09:19:34 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_cd(t_token_list *lst)
{
	t_token_list	*cmd;
	int				destiny_len;
	char			*destiny_path;

	cmd = lst->next;
	destiny_path = NULL;
	while (cmd && cmd->type == WORD)
	{
		destiny_path = cmd->lexeme;
		destiny_len = ft_strlen(destiny_path);
		if (ft_strncmp(destiny_path, "~", 1) == 0)
			builtins_cd_switch_home_dir();
		else if (chdir(destiny_path) != 0)
			error_cd_messenger(destiny_len, destiny_path);
		else if (destiny_path[0] == '.' && destiny_path[0] == '\0')
			write(2, "\n", 1);
		else if (ft_strncmp(destiny_path, "..", 2) == 0)
			builtins_cd_switch_old_dir();
		else
			builtins_cd_switch_new_dir(destiny_path);
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

void	builtins_cd_switch_new_dir(char *destiny_path)
{
	char	*actual_path;

	actual_path = NULL;
	actual_path = getcwd(actual_path, 100);
	destiny_path = ft_strjoin(actual_path, "/");
	chdir(destiny_path);
}

void	builtins_cd_switch_home_dir(void)
{
	char	*home_path;

	home_path = NULL;
	home_path = lookup_table(env_holder(NULL, false, false), "HOME")->value;
	home_path = ft_strjoin(home_path, "/");
	chdir(home_path);
}

void	builtins_cd_switch_old_dir(void)
{
	char	*actual_path;
	char	*old_path;

	actual_path = NULL;
	old_path = NULL;
	actual_path = getcwd(actual_path, 100);
	old_path = ft_strrchr(actual_path, '/');
	old_path = ft_strjoin(old_path, "/");
	chdir(old_path);
}