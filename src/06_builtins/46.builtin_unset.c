/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   46.builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:08:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/08 13:04:22 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_unset(char *arg)
{
	t_env_entry	*next;
	t_env_entry	*tmp;
	char		*var_key;

	next = NULL;
	var_key = ft_strdup(++arg);
	arg--;
	tmp = env_holder(NULL, false, false);
	ft_lst_remove_node(tmp, next, var_key);
	free(var_key);
}

void	ft_lst_remove_node(t_env_entry *tmp, t_env_entry *next,
	const char *var_key)
{
	while (tmp != NULL)
	{
		if (ft_strcmp(var_key, tmp->key) == 0)
		{
			if (tmp->prev == NULL)
			{
				next = tmp->next;
				free(tmp->value);
				free(tmp->key);
				free(tmp);
				tmp = next;
				return ;
			}
			tmp->prev->next = tmp->next;
			// tmp->next->prev = tmp->prev;
			free(tmp->value);
			free(tmp->key);
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}
