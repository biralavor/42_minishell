/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.builtins_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/13 15:58:55 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "error_manager.h"
#include "executor.h"
#include "builtins.h"

/**
 * @brief:
 * @param var_key the name of the variable to export.
 * @param var_value the value to be setted in the var_key.
 * TODO: Use var_key and var_value to set the environment variable.
*/
void	builtins_runner_export(t_env_entry *env_vars)
{
	char		*var_key;
	char		*var_value;
	t_env_entry	*env_sorted;

	var_key = NULL;
	var_value = NULL;
	env_sorted = builtins_env_sort_manager(env_vars);
	while (env_sorted)
	{
		var_key = env_sorted->key;
		var_value = env_sorted->value;
		ft_printf("declare -x %s=%s\n", var_key, var_value);
		env_sorted = env_sorted->next;
	}
}

t_env_entry	*builtins_env_sort_manager(t_env_entry *env_vars)
{
	t_env_entry	*tmp;

	tmp = env_vars;
	while (tmp && tmp->next && !builtins_is_env_sorted(tmp))
		tmp = bubble_sort_nodes(&tmp);
	return (tmp);
}

bool	builtins_is_env_sorted(t_env_entry *env_vars)
{
	t_env_entry	*tmp;

	tmp = env_vars;
	while (tmp && tmp->next)
	{
		if (ft_strncmp(tmp->key, tmp->next->key, ft_strlen(tmp->key)) > 0)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void	swap_env_nodes(t_env_entry **head, t_env_entry *a, t_env_entry *b)
{
	t_env_entry	*prev_a;
	t_env_entry	*next_b;

	prev_a = a->prev;
	next_b = b->next;
	if (prev_a != NULL)
		prev_a->next = b;
	else
		*head = b;
	if (next_b != NULL)
		next_b->prev = a;
	b->prev = prev_a;
	b->next = a;
	a->prev = b;
	a->next = next_b;
}

t_env_entry	*bubble_sort_nodes(t_env_entry **head)
{
	bool		swapped;
	t_env_entry	*cur;

	swapped = true;
	cur = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return (*head);
	while (swapped)
	{
		swapped = false;
		cur = *head;
		while (cur && cur->next != NULL)
		{
			if (ft_strncmp(cur->key, cur->next->key, ft_strlen(cur->key)) > 0)
			{
				swap_env_nodes(head, cur, cur->next);
				swapped = true;
			}
			else
				cur = cur->next;
		}
		if (!swapped)
			break ;
	}
	return (*head);
}
