/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   46.builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:08:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/09 12:31:05 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_unset(char *arg)
{
	t_env_entry	*next;
	t_env_entry	*tmp;
	char		*var_key;

	next = NULL;
	var_key = NULL;
	tmp = copy_env_table(env_holder(NULL, false, false));
	if (*arg == '$')
	{
		var_key = ft_strdup(++arg);
		arg--;
		ft_lst_remove_node(tmp, next, var_key);
		free(var_key);
	}
	else
		ft_lst_remove_node(tmp, next, arg);
}

void	ft_lst_remove_node(t_env_entry *tmp, t_env_entry *next,
	const char *var_key)
{
	next = tmp;
	while (tmp)
	{
		if (ft_strcmp(var_key, tmp->key) == 0)
		{
			if (tmp->prev == NULL)
			{
				next = tmp->next;
				tmp->next->prev = NULL;
				if (tmp->value)
					free(tmp->value);
				free(tmp->key);
				free(tmp);
				(void)env_holder(next, true, false);
				return ;
			}
			tmp->prev->next = tmp->next;
			if(tmp->next)
				tmp->next->prev = tmp->prev;
			next = tmp->prev;
			if (tmp->value)
				free(tmp->value);
			free(tmp->key);
			free(tmp);
			tmp = goto_head_env_table(next);
			(void)env_holder(tmp, true, false);
			return ;
		}
		tmp = tmp->next;
	}
	free_env_table(&next);
}
