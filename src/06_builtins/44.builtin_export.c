/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   44.builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:23:46 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/08 23:39:46 by umeneses         ###   ########.fr       */
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
	env_copy = copy_env_table_manager(env_holder(NULL, false, false));
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

t_env_entry	*copy_env_table_manager(t_env_entry *env_vars)
{
	t_env_entry	*env_copy;
	t_env_entry	*head;
	t_env_entry	*curr;

	env_copy = NULL;
	head = NULL;
	curr = NULL;
	if (!env_vars)
		return (NULL);
	if (!env_vars->key || !env_vars->value || !env_vars->size)
		return (NULL);
	env_copy = create_new_entry(env_vars->key, env_vars->value, env_vars->size);
	if (!env_copy)
	{
		ft_putendl_fd("Error: Failed to create new entry", STDERR_FILENO);
		return (NULL);
	}
	env_copy = copy_env_table_runner(env_vars, env_copy, head, curr);
	return (env_copy);
}

t_env_entry	*copy_env_table_runner(t_env_entry *env_vars,
			t_env_entry *env_copy, t_env_entry *head, t_env_entry *curr)
{
	head = env_vars->next;
	curr = env_copy;
	while (head != NULL)
	{
		curr->next = create_new_entry(head->key, head->value, head->size);
		if (!curr->next)
		{
			ft_putendl_fd("Error: Failed to create new entry", STDERR_FILENO);
			free_env_table(&env_copy);
			return (NULL);
		}
		curr->next->prev = curr;
		curr = curr->next;
		head = head->next;
	}
	return (env_copy);
}
