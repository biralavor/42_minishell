/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   28.builtins_export_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/13 18:50:52 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "executor.h"
#include "builtins.h"

void	arg_handle_runner(t_env_entry *env_vars, char *arg)
{
	char		*var_key;
	char		*var_value;
	char		*equal_sign;

	equal_sign = ft_strchr(arg, '=');
	if (equal_sign)
	{
		var_key = ft_substr(arg, 0, equal_sign - arg);
		var_value = ft_strdup(equal_sign + 1);
		env_vars = addto_env_table(env_vars, var_key, var_value);
	}
	else
		env_vars = addto_env_table(env_vars, arg, "");
	env_vars = env_holder(env_vars, true);
}

int	arg_handle_state_detector(int state, char *arg)
{
	if (!arg)
		return (state = 0);
	else if (arg[0] >= 'A' && arg[0] <= 'Z')
		return (state = 100);
	else if (arg[0] == '_')
		return (state = 101);
	else if (arg[0] >= 'a' && arg[0] <= 'z')
		return (state = 200);
	else
		return (state = 404);
}

void	ft_env_printer_classic(t_env_entry *env_vars)
{
	char	*var_key;
	char	*var_value;

	var_key = NULL;
	var_value = NULL;
	while (env_vars)
	{
		var_key = env_vars->key;
		var_value = env_vars->value;
		ft_printf("declare -x %s=%s\n", var_key, var_value);
		env_vars = env_vars->next;
	}
}
