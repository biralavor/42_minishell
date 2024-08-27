/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   27.builtins_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/26 19:26:27 by umeneses         ###   ########.fr       */
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
	t_env_entry	*tmp;

	state = 0;
	tmp = goto_head_env_table(env_vars);
	env_sorted = NULL;
	state = arg_handle_state_detector(state, arg);
	if (state == 0)
	{
		env_sorted = builtins_env_sort_manager(tmp);
		ft_env_printer_classic(env_sorted);
	}
	else if (state == 100 || state == 101 || state == 200)
	{
		arg_handle_runner(tmp, arg);
		env_sorted = builtins_env_sort_manager(tmp);
		ft_env_printer_classic(env_sorted);
	}
	else if (state == 404)
	{	
		write(2, "minishell: export: `", 20);
		write(2, arg, ft_strlen(arg));
		write(2, "': not a valid identifier\n", 26);
	}
}

t_env_entry	*builtins_env_sort_manager(t_env_entry *env_vars)
{
	t_env_entry	*current;
	t_env_entry	*sorted;
	t_env_entry	*next_node;

	current = env_holder(NULL, false, false);
	sorted = NULL;
	next_node = NULL;
	if (builtins_is_env_sorted(env_vars))
		return (env_vars);
	while(current)
	{
		next_node = current->next;
		sorted = sorted_env_insert(&sorted, current);
		current = next_node;
	}
	return(sorted);
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
