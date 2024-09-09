/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   25.builtins_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 16:10:04 by umeneses         ###   ########.fr       */
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
		if (ft_strncmp(destiny_path, "..", 2) == 0)
			builtins_cd_switch_parent_dir();
		else if (chdir(destiny_path) != 0)
			cd_error_msg(destiny_len, destiny_path, chdir(destiny_path));
		else
			builtins_cd_switch_new_dir(destiny_path);
		cmd = cmd->next;
	}
	if (!destiny_path)
		builtins_cd_switch_home_dir();
}

void	builtins_cd_switch_new_dir(char *destiny_path)
{
	char	*actual_path;

	actual_path = NULL;
	actual_path = getcwd(actual_path, 100);
	destiny_path = ft_strjoin(actual_path, "/");
	chdir(destiny_path);
	free(destiny_path);
	free(actual_path);
	exit_status_holder(0, true);
}

void	builtins_cd_switch_home_dir(void)
{
	char	*home_path;

	home_path = NULL;
	home_path = lookup_table(env_holder(NULL, false, false), "HOME")->value;
	home_path = ft_strjoin(home_path, "/");
	chdir(home_path);
	free(home_path);
	exit_status_holder(0, true);
}

void	builtins_cd_switch_parent_dir(void)
{
	int		idx;
	char	*actual_path;
	char	*parent_path;

	idx = 0;
	actual_path = NULL;
	parent_path = NULL;
	actual_path = getcwd(actual_path, 100);
	parent_path = actual_path;
	while (actual_path[idx])
		idx++;
	while (parent_path[idx] != '/')
	{
		parent_path[idx] = '\0';
		idx--;
	}
	chdir(parent_path);
	free(actual_path);
	exit_status_holder(0, true);
}
