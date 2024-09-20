/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   46.builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:08:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/20 14:54:52 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_unset(char *arg)
{
	ft_lst_remove_node(env_holder(NULL, false, false), arg);
}

void	ft_lst_remove_node(t_env_entry *env_table, const char *arg)
{
	t_env_entry	*next;
	t_env_entry	*prev;

	next = NULL;
	prev = NULL;
	while (env_table != NULL)
	{
		if (ft_strncmp(env_table->key, arg, ft_strlen(env_table->key)) == 0)
		{
			next = env_table->next;
			prev = env_table->prev;
			prev->next = next;
			next->prev = prev;
			free(env_table->value);
			free(env_table->key);
			free(env_table);
			// env_holder(env_table, true, false);
			return ;
		}
		env_table = env_table->next;
	}
}
