/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   46.builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:08:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/09 10:59:04 by tmalheir         ###   ########.fr       */
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
	tmp = env_holder(NULL, false, false);
	if (*arg == '$')
	{
		var_key = ft_strdup(++arg);
		arg--;
		ft_lst_remove_node(&tmp, next, var_key);
		free(var_key);
	}
	else
		ft_lst_remove_node(&tmp, next, arg);
}

void	ft_lst_remove_node(t_env_entry **tmp, t_env_entry *next,
	const char *var_key)
{
	while (tmp != NULL)
	{
		if (ft_strcmp(var_key, (*tmp)->key) == 0)
		{
			if ((*tmp)->prev == NULL)
			{
				next = (*tmp)->next;
				(*tmp)->next->prev = NULL;
				(void)env_holder(next, true, false);
				if ((*tmp)->value)
					free((*tmp)->value);
				free((*tmp)->key);
				free((*tmp));
				// (*tmp) = next;
				return ;
			}
			(*tmp)->prev->next = (*tmp)->next;
			(*tmp)->next->prev = (*tmp)->prev;
			if ((*tmp)->value)
				free((*tmp)->value);
			free((*tmp)->key);
			free((*tmp));
			return ;
		}
		*tmp = (*tmp)->next;
	}
}
