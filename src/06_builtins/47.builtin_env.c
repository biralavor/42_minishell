/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   47.builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/09 22:55:23 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_env(void)
{
	char		*var_key;
	char		*var_value;
	t_env_entry	*env_vars;

	var_key = NULL;
	var_value = NULL;
	env_vars = goto_head_env_table(env_holder(NULL, false, false));
	if (!env_vars)
	{
		ft_putendl_fd("Error: Could not find environment variables",
			STDERR_FILENO);
		exit_status_holder(1, true);
		return ;
	}
	while (env_vars)
	{
		var_key = env_vars->key;
		var_value = env_vars->value;
		ft_putstr_fd(var_key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putendl_fd(var_value, STDOUT_FILENO);
		env_vars = env_vars->next;
	}
	exit_status_holder(0, true);
}
