/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23.builtins_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/19 09:26:13 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins_manager(char **cmd)
{
	int	idx;

	idx = -1;
	while (cmd[++idx])
	{
		if (ft_strncmp(cmd[idx], "echo", 4) == 0)
			idx = builtins_runner_echo(cmd, idx);
		// else if (ft_strncmp(cmd[idx], "cd", 2) == 0)
		// 	builtins_runner_cd(tmp);
		// else if (ft_strncmp(cmd[idx], "pwd", 3) == 0)
		// 	builtins_runner_pwd(tmp);
		if (NULL == cmd[idx])
				break ;
	}

	// else if (builtins_detector_with_possible_args(cmd))
	// 	builtins_with_possible_args_manager(cmd);
	return (idx);
}

bool	builtins_detector(char **cmd)
{
	int	idx;

	idx = 0;
	while (cmd[idx])
	{
		if ((ft_strncmp(cmd[idx], "echo", 4) == 0)
			|| (ft_strncmp(cmd[idx], "cd", 2) == 0)
			|| (ft_strncmp(cmd[idx], "pwd", 3) == 0)
			|| (ft_strncmp(cmd[idx], "exit", 4) == 0))
			return (true);
		idx++;
	}
	return (false);
}

bool	builtins_detector_with_possible_args(t_token_list *lst)
{
	t_token_list	*tmp;

	tmp = lst;
	while (tmp && tmp->type == WORD)
	{
		if ((ft_strncmp(tmp->lexeme, "export", 6) == 0)
			|| (ft_strncmp(tmp->lexeme, "unset", 5) == 0)
			|| (ft_strncmp(tmp->lexeme, "env", 3) == 0))
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	builtins_with_possible_args_manager(t_token_list *lst)
{
	t_token_list	*tmp;
	t_env_entry		*env_vars;

	tmp = lst;
	env_vars = env_holder(NULL, false, false);
	while (tmp)
	{
		if (ft_strncmp(tmp->lexeme, "export", 6) == 0)
		{
			if (tmp->next && tmp->next->type == WORD)
				builtins_runner_export(env_vars, tmp->next->lexeme);
			else
				builtins_runner_export(env_vars, NULL);
		}
		else if (ft_strncmp(tmp->lexeme, "unset", 5) == 0)
		{
			if (tmp->next && tmp->next->type == WORD)
				builtins_runner_unset(env_vars, tmp->next->lexeme);
		}
		else if (ft_strncmp(tmp->lexeme, "env", 3) == 0)
			builtins_runner_env(env_vars);
		tmp = tmp->next;
	}
}
