/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   28.builtins_export_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/16 09:45:46 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	arg_handle_runner(t_env_entry *env_vars, char *arg)
{
	char		*var_key;
	char		*var_value;
	char		*equal_sign;
	t_env_entry	*tmp;

	tmp = env_vars;
	equal_sign = ft_strchr(arg, '=');
	if (equal_sign)
	{
		var_key = ft_substr(arg, 0, equal_sign - arg);
		var_value = ft_strdup(equal_sign + 1);
		tmp = addto_env_table(tmp, var_key, var_value);
		free(var_key);
		free(var_value);
	}
	else
		tmp = addto_env_table(tmp, arg, "");
	tmp = env_holder(tmp, true, false);
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
	t_env_entry	*tmp;

	tmp = env_vars;
	while (tmp)
	{
		ft_printf("declare -x %s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}
