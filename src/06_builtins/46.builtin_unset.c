/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   29.builtins_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:08:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/02 23:04:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_unset(char *arg)
{
	t_env_entry	*toremove;
	t_env_entry	*updated_table;

	toremove = NULL;
	toremove = lookup_table(env_holder(NULL, false, false), arg);
	if (toremove)
	{
		updated_table = removefrom_env_table(toremove);
		updated_table = env_holder(updated_table, true, false);
	}
}

t_env_entry	*removefrom_env_table(t_env_entry *toremove)
{
	t_env_entry	*tmp;

	tmp = env_holder(NULL, false, false);
	while (tmp)
	{
		if (tmp == toremove)
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			// if (tmp == env_vars)
			// 	env_vars = tmp->next;
			free(tmp->key);
			free(tmp->value);
			// free(tmp);
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
