/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   30.builtins_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/15 14:10:35 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "executor.h"
#include "builtins.h"

void	builtins_runner_env(t_env_entry *env_vars)
{
	char	*var_key;
	char	*var_value;

	var_key = NULL;
	var_value = NULL;
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
