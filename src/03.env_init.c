/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:58:32 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/24 10:54:51 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	environment_init(char **envp)
{
	char		*key;
	char		*value;
	char		*equal_sign;
	t_env_entry	*env_table;

	env_table = NULL;
	while (envp && *envp)
	{
		equal_sign = ft_strchr(*envp, '=');
		if (equal_sign)
		{
			key = ft_substr(*envp, 0, equal_sign - *envp);
			value = ft_strdup(equal_sign + 1);
			addto_env_table(&env_table, create_new_entry(key, value, ft_array_len(envp)));
			free(key);
			free(value);
		}
		envp++;
	}
	env_holder(env_table, true, false);
}

t_env_entry	*alloc_table(int init_size)
{
	t_env_entry	*table;

	table = (t_env_entry *)ft_calloc(1, sizeof(t_env_entry));
	if (!table)
		return (NULL);
	table->next = NULL;
	table->prev = NULL;
	table->key = NULL;
	table->value = NULL;
	table->size = init_size;
	return (table);
}

t_env_entry	*env_holder(t_env_entry *table, bool update, bool clear_table)
{
	static t_env_entry	*env_table_holder;

	if (table)
	{
		if (!env_table_holder && table->key)
			env_table_holder = table;
		else if (env_table_holder && table->key && update)
		{
			if (env_table_holder && (env_table_holder != table))
				free_env_table(&env_table_holder);
			env_table_holder = table;
		}
	}
	else if (env_table_holder && clear_table)
	{
		free_env_table(&env_table_holder);
		free(env_table_holder);
	}
	return (env_table_holder);
}

t_env_entry	*create_new_entry(const char *key, const char *value, int size)
{
	t_env_entry	*new_entry;

	new_entry = alloc_table(size);
	if (!new_entry)
	{
		ft_putendl_fd("Error: Could not create new entry", STDERR_FILENO);
		exit (exit_status_holder(1, true));
	}
	new_entry->key = ft_strdup(key);
	new_entry->value = ft_strdup(value);
	return (new_entry);
}

void	addto_env_table(t_env_entry **table, t_env_entry *new_entry)
{
	if (table && new_entry)
	{
		if (!(*table))
			*table = new_entry;
		else
		{
			new_entry->prev = goto_end_env_table(*table);
			goto_end_env_table(*table)->next = new_entry;
		}
	}
}

t_env_entry	*lookup_table(t_env_entry *table, char *key)
{
	t_env_entry	*entry;

	entry = goto_head_env_table(table);
	while (entry != NULL)
	{
		if (ft_strncmp(entry->key, key, ft_strlen(entry->key)) == 0)
			return (entry);
		entry = entry->next;
	}
	return (NULL);
}
