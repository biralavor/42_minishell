/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   44.builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/24 11:23:18 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * TODO: fix memory leaks in this function.
 */
void	builtins_runner_export(char *arg)
{
	int			state;
	t_env_entry	*env_sorted;
	t_env_entry	*env_copy;

	state = 0;
	env_sorted = NULL;
	env_copy = copy_env_table(env_holder(NULL, false, false));
	state = arg_handle_state_detector(state, arg);
	if (state == 0)
	{
		env_sorted = builtins_env_sort_manager(env_copy);
		ft_env_printer_classic(env_sorted);
		free_env_table(&env_sorted);
	}
	else if (state == 100)
	{
		arg_handle_runner(env_copy, arg);
		env_sorted = builtins_env_sort_manager(env_copy);
		free_env_table(&env_sorted);
	}
	else if (state == 404)
	{
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		free_env_table(&env_copy);
		exit_status_holder(1, true);
	}
}

t_env_entry	*copy_env_table(t_env_entry *env_vars)
{
	t_env_entry	*env_copy;
	t_env_entry	*head;
	t_env_entry	*curr;

	env_copy = create_new_entry(env_vars->key, env_vars->value, env_vars->size);
	if (!env_vars)
		return (NULL);
	head = env_vars->next;
	curr = env_copy;
	while (head != NULL)
	{
		curr->next = create_new_entry(head->key, head->value, head->size);
		curr->next->prev = curr;
		curr = curr->next;
		head = head->next;
	}
	return (env_copy);
}

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
		if (ft_strncmp(tmp->key, tmp->next->key, ft_strlen(tmp->key)) > 0)
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
	while (curr && ft_strncmp(curr->key, new->key, ft_strlen(curr->key)) <= 0)
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
