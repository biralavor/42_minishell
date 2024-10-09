/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   51.command_runner_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:43:43 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/08 21:27:59 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**convert_envs_to_array(t_env_entry *env_vars)
{
	int			idx;
	char		**all_envs;
	char		*updated_key;
	t_env_entry	*tmp;

	idx = 0;
	all_envs = NULL;
	tmp = env_vars;
	all_envs = (char **)ft_calloc(1, sizeof(char **) * (env_vars->size + 1));
	while (tmp)
	{
		updated_key = ft_strjoin(tmp->key, "=");
		all_envs[idx] = ft_strjoin(updated_key, tmp->value);
		tmp = tmp->next;
		free(updated_key);
		idx++;
	}
	return (all_envs);
}

bool	is_cmd_with_absolute_path(char *cmd_name)
{
	if (access(cmd_name, F_OK) == 0 && ft_strchr(cmd_name, '/'))
		return (true);
	return (false);
}

char	*testing_all_paths_with_cmd(char **all_paths, char *cmd_name)
{
	int		idx;
	char	*to_execute;
	char	*path_with_slash;

	to_execute = NULL;
	path_with_slash = NULL;
	idx = 0;
	if (!all_paths)
		return (ft_strdup(""));
	while (all_paths[idx])
	{
		path_with_slash = ft_strjoin(all_paths[idx], "/");
		to_execute = ft_merge_strings(path_with_slash, ft_strdup(cmd_name));
		if (is_cmd_with_absolute_path(to_execute))
			return (to_execute);
		free(to_execute);
		to_execute = NULL;
		idx++;
	}
	return (ft_strdup(cmd_name));
}
