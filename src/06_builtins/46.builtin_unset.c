/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   46.builtin_unset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:08:16 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/07 20:08:34 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtins_runner_unset(char *arg)
{
	t_env_entry	*next;
	t_env_entry	*tmp;

	next = NULL;
	tmp = env_holder(NULL, false, false);
	ft_lst_remove_node(tmp, next, arg);
}

void	ft_lst_remove_node(t_env_entry *tmp, t_env_entry *next,
	const char *arg)
{
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->key, arg, ft_strlen(arg)) == 0)
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
