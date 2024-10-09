/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_sort_manager.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 23:27:05 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/08 23:53:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_entry	*builtins_env_sort_manager(t_env_entry *current)
{
	t_env_entry	*sorted;
	t_env_entry	*next_node;

	sorted = NULL;
	next_node = NULL;
	if (builtins_is_env_sorted(current))
		return (current);
	while (current)
	{
		next_node = current->next;
		sorted = sorted_env_insert(&sorted, current);
		current = next_node;
	}
	return (sorted);
}

bool	builtins_is_env_sorted(t_env_entry *env_vars)
{
	t_env_entry	*tmp;

	tmp = env_vars;
	while (tmp && tmp->next)
	{
		if (ft_strcmp(tmp->key, tmp->next->key) > 0)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

t_env_entry	*sorted_env_insert(t_env_entry **head, t_env_entry *new)
{
	t_env_entry	*curr;
	t_env_entry	*prev;

	curr = *head;
	prev = NULL;
	while (curr && ft_strcmp(curr->key, new->key) <= 0)
	{
		prev = curr;
		curr = curr->next;
	}
	new->next = curr;
	if (prev == NULL)
		*head = new;
	else
		prev->next = new;
	new->prev = prev;
	if (curr)
		curr->prev = new;
	return (*head);
}
