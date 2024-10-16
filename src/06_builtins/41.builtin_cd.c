/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   41.builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/11 01:22:51 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	check_lst_next(t_token_list *lst)
{
	if (!lst->next)
	{
		builtins_cd_switch_home_dir();
		return (false);
	}
	return (true);
}

static void	update_oldpwd(int alterable, char *str)
{
	char		cwd[PATH_MAX];
	t_env_entry	*tmp;

	tmp = env_holder(NULL, false, false);
	getcwd(cwd, PATH_MAX);
	while (tmp)
	{
		if (ft_strcmp(tmp->key, "OLDPWD") == 0)
		{
			free(tmp->value);
			if (!alterable)
				tmp->value = ft_strdup(cwd);
			else
				tmp->value = ft_strdup(str);
			tmp = goto_head_env_table(tmp);
			(void)env_holder(tmp, true, false);
			break ;
		}
		else
			tmp = tmp->next;
	}
}

static bool	check_extra_args(t_token_list *cmd)
{
	if (cmd->lexeme && cmd->next && cmd->next->lexeme)
	{
		write(STDERR_FILENO, "bash cd: too many arguments\n", 28);
		exit_status_holder(1, true);
		return (true);
	}
	return (false);
}

void	builtins_runner_cd(t_token_list *lst)
{
	t_token_list	*cmd;
	char			*destiny_path;
	char			actual_path[PATH_MAX];

	if (!check_lst_next(lst))
		return ;
	cmd = lst->next;
	destiny_path = NULL;
	ft_bzero(actual_path, PATH_MAX);
	if (check_extra_args(cmd))
		return ;
	while (cmd && cmd->type == WORD)
	{
		if (!cmd->lexeme)
			return ;
		destiny_path = ft_strdup(cmd->lexeme);
		getcwd(actual_path, PATH_MAX);
		if (chdir(destiny_path) != 0)
		{
			cd_error_msg(ft_strlen(destiny_path), destiny_path,
				chdir(destiny_path));
			break ;
		}
		update_oldpwd(1, actual_path);
		cmd = cmd->next;
		// exit_status_holder(0, true);
	}
	free(destiny_path);
}

void	builtins_cd_switch_home_dir(void)
{
	char	*home_path;

	update_oldpwd(0, NULL);
	home_path = NULL;
	home_path = lookup_table(env_holder(NULL, false, false), "HOME")->value;
	home_path = ft_strjoin(home_path, "/");
	chdir(home_path);
	free(home_path);
	// exit_status_holder(0, true);
}
