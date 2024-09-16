/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   44.builtin_export_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/15 18:14:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	}
	else
	{
		var_key = ft_strdup(arg);
		var_value = ft_strdup("");
	}
	if (lookup_table(env_vars, var_key))
		replace_env_var(env_vars, var_key, var_value);
	else
		addto_env_table(&env_vars, create_new_entry(var_key, var_value, env_vars->size));
	free(var_key);
	free(var_value);
	// env_holder(env_vars, true, false);
}

void	replace_env_var(t_env_entry *env_vars, char *var_key, char *var_value)
{
	while (env_vars)
	{
		if (ft_strncmp(env_vars->key, var_key, ft_strlen(var_key)) == 0)
		{
			free(env_vars->value);
			env_vars->value = ft_strdup(var_value);
			break ;
		}
		env_vars = env_vars->next;
	}
	env_vars = goto_head_env_table(env_vars);
}

int	arg_handle_state_detector(int state, char *arg)
{
	int idx;

	idx = 0;
	if (!arg)
		return (state = 0);
	else if (env_var_key_rules_at_start(arg[idx]))
	{
		while (++idx)
		{
			if (env_var_key_rules_at_middle(arg[idx]))
				if (arg[idx + 1] == '\0')
					return (state = 100);
		}
	}
	return (state = 404);
}

void	ft_env_printer_classic(t_env_entry *env_vars)
{
	t_env_entry	*tmp;

	tmp = env_vars;
	while (tmp)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(tmp->key, STDOUT_FILENO);
		ft_putstr_fd("=", STDOUT_FILENO);
		ft_putendl_fd(tmp->value, STDOUT_FILENO);
		tmp = tmp->next;
	}
}