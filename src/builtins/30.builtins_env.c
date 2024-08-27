/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30.builtins_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/27 09:13:37 by umeneses         ###   ########.fr       */
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
	env_vars = env_holder(NULL, false, false);
	if (!env_vars)
		return ;
	else
	{
		while (env_vars)
		{
			var_key = env_vars->key;
			var_value = env_vars->value;
			ft_printf("%s=%s\n", var_key, var_value);
			env_vars = env_vars->next;
		}
	}
}
