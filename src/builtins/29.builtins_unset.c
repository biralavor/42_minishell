/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   29.builtins_unset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:08:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/14 15:08:30 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "executor.h"
#include "builtins.h"

void	builtins_runner_unset(t_env_entry *env_vars, char *arg)
{
	t_env_entry	*toremove;

	toremove = NULL;
	toremove = lookup_table(env_vars, arg);
	if (toremove)
	{
		env_vars = removefrom_env_table(env_vars, toremove);
		env_vars = env_holder(env_vars, true);
	}
}

t_env_entry	*removefrom_env_table(t_env_entry *env_vars, t_env_entry *toremove)
{
	t_env_entry	*tmp;

	tmp = env_vars;
	while (tmp)
	{
		if (tmp == toremove)
		{
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			if (tmp == env_vars)
				env_vars = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return (env_vars);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
