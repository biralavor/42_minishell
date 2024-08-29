/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   33.execve_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:43:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/20 17:26:41 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * TODO: implementar função que trata expansão de variável
 */
char	**convert_envs_to_array(t_env_entry *env_vars)
{
	int			idx;
	char		**all_envs;
	t_env_entry	*tmp;

	idx = 0;
	all_envs = NULL;
	tmp = env_vars;
	all_envs = (char **)ft_calloc(1, sizeof(char **) * (env_vars->size + 1));
	while (tmp)
	{
		all_envs[idx] = ft_strjoin(tmp->key, "=");
		all_envs[idx] = ft_strjoin(all_envs[idx], tmp->value);
		tmp = tmp->next;
		idx++;
	}
	return (all_envs);
}

/**
 * TODO: implementar função que trata expansão de variável
 */
char	**convert_tokens_to_array(t_token_list *lst)
{
	int				size;
	char			**cmd;
	t_token_list	*tmp;

	cmd = NULL;
	tmp = lst;
	size = ft_lst_size(lst);
	cmd = (char **)ft_calloc(1, sizeof(char **) * (size + 1));
	while (tmp)
	{
		cmd[tmp->idx] = ft_strdup(tmp->lexeme);
		tmp = tmp->next;
	}
	return (cmd);
}

bool	is_cmd_with_valid_path(char *cmd_name)
{
	if (access(cmd_name, F_OK) == 0)
		return (true);
	return (false);
}

char	*testing_all_paths_with_cmd(char **all_paths, char *cmd_name)
{
	int		idx;
	char	*to_execute;

	to_execute = NULL;
	idx = 0;
	while (all_paths[idx])
	{
		all_paths[idx] = ft_strjoin(all_paths[idx], "/");
		to_execute = ft_strjoin(all_paths[idx], ft_strdup(cmd_name));
		if (is_cmd_with_valid_path(to_execute))
			return (to_execute);
		free(to_execute);
		to_execute = NULL;
		idx++;
	}
	return (NULL);
}
