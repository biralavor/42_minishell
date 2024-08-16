/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.builtins_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/16 09:45:39 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * TODO: fix memory leaks in this function.
 */
void	builtins_runner_export(t_env_entry *env_vars, char *arg)
{
	int			state;
	t_env_entry	*env_sorted;

	state = 0;
	state = arg_handle_state_detector(state, arg);
	if (state == 0)
	{
		env_sorted = builtins_env_sort_manager(env_vars);
		ft_env_printer_classic(env_sorted);
	}
	else if (state == 100 || state == 101 || state == 200)
	{
		arg_handle_runner(env_vars, arg);
		env_sorted = builtins_env_sort_manager(env_vars);
		ft_env_printer_classic(env_sorted);
	}
	else if (state == 404)
	{	
		write(2, "minishell: export: `", 20);
		write(2, arg, ft_strlen(arg));
		write(2, "': not a valid identifier", 25);
		write(2, "\n", 1);
	}
}

t_env_entry	*builtins_env_sort_manager(t_env_entry *env_vars)
{
	t_env_entry	*tmp;

	tmp = env_vars;
	if (!builtins_is_env_sorted(tmp))
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

	if (head == NULL || *head == NULL || a == NULL || b == NULL || a == b)
		return ;
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
				cur = cur->prev;
			}
			else
				cur = cur->next;
		}
		if (!swapped)
			break ;
	}
	return (*head);
}
