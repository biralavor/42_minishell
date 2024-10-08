/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   44.builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/09 23:29:39 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	else if (state == 100 || state == 200)
		arg_handle_runner(env_copy, arg);
	else if (state == 404)
	{
		ft_putstr_fd("minishell: export: `", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
		free_env_table(&env_copy);
		exit_status_holder(EXIT_FAILURE, true);
	}
}

t_env_entry	*copy_env_table(t_env_entry *env_vars)
{
	t_env_entry	*env_copy;
	t_env_entry	*head;
	t_env_entry	*curr;

	if (!env_vars || !env_vars->key || !env_vars->value || !env_vars->size)
		return (NULL);
	env_copy = create_entry_copy(env_vars);
	if (!env_copy)
		return (NULL);
	head = env_vars->next;
	curr = env_copy;
	while (head != NULL)
	{
		curr->next = create_entry_copy(head);
		if (!curr->next)
		{
			free_env_table(&env_copy);
			return (NULL);
		}
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
