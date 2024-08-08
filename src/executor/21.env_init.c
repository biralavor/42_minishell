/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21.env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:58:32 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/08 12:39:27 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/**
 * TODO: Implement a function to free the table: destroy_table(). ***
 * ***
 * @brief Initializes the environment table.
 * @param envp -> a system array of strings that define the
 * current environment variables.
 * While envp is not NULL, it will iterate through the environment
 * variables and add them to the table. When ft_strchr finds the first '=',
 * it copies the string before the '=' to KEY (at position equal_sign - *envp)
 * and the string after the '=' to VALUE.
 */
void	environment_init(char **envp)
{
	t_env_entry	*env_table;
	char		*key;
	char		*value;
	char		*equal_sign;

	env_table = alloc_table(ft_array_len(envp));
	if (!env_table)
	{
		ft_putendl_fd("Error: Could not create environment table", 2);
		exit (EXIT_FAILURE);
	}
	while (envp && *envp)
	{
		equal_sign = ft_strchr(*envp, '=');
		if (equal_sign)
		{
			key = ft_substr(*envp, 0, equal_sign - *envp);
			value = ft_strdup(equal_sign + 1);
			if (key && value)
				env_table = addto_env_table(env_table, key, value);
			free(key);
			free(value);
		}
		envp++;
	}
	ft_env_printer(env_table);
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

t_env_entry	*addto_env_table(t_env_entry *table, const char *key,
							const char *value)
{
	t_env_entry	*new_entry;

	new_entry = alloc_table(table->size);
	new_entry->key = ft_strdup(key);
	new_entry->value = ft_strdup(value);
	if (table->next == NULL && table->prev == NULL
		&& table->key == NULL && table->value == NULL)
		return (new_entry);
	while (table)
	{
		if (table->next == NULL)
			break ;
		table = table->next;
	}
	new_entry->prev = table;
	table->next = new_entry;
	return (table);
}

char	*lookup_table(t_env_entry *table, char *key)
{
	t_env_entry	*entry;

	entry = table;
	while (entry != NULL)
	{
		if (ft_strncmp(entry->key, key, ft_strlen(key)) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}
