/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21.env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:58:32 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/07 16:49:29 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

/**
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
	t_env_table	*env_table;
	char		*key;
	char		*value;
	char		*equal_sign;

	env_table = create_table(50);
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
				addto_env_table(env_table, key, value);
			free(key);
			free(value);
		}
		envp++;
	}
	ft_env_printer(env_table);
}

t_env_table	*create_table(int init_size)
{
	t_env_table	*table;

	table = (t_env_table *)ft_calloc(1, sizeof(t_env_table));
	if (!table)
		return (NULL);
	table->head = NULL;
	table->head = (t_env_entry **)ft_calloc(init_size, sizeof(t_env_table *));
	if (!table->head)
	{
		free(table);
		return (NULL);
	}
	table->size = init_size;
	return (table);
}

void	addto_env_table(t_env_table *table, const char *key, const char *value)
{
	int			hash;
	t_env_entry	*new_entry;
	float		load_factor;

	hash = hash_maker(key, table->size);
	new_entry = (t_env_entry *)ft_calloc(1, sizeof(t_env_entry));
	if (!new_entry)
		return ;
	new_entry->key = ft_strdup(key);
	new_entry->value = ft_strdup(value);
	new_entry->next = table->head[hash];
	load_factor = (float)table->size / (float)(table->size + 1);
	if (load_factor >= 0.75 && table->size <= 100)
		resize_table(table);
	table->head[hash] = new_entry;
}

char	*lookup_table(t_env_table *table, char *key)
{
	int			hash;
	t_env_entry	*entry;

	hash = hash_maker(key, table->size);
	entry = table->head[hash];
	while (entry != NULL)
	{
		if (ft_strncmp(entry->key, key, ft_strlen(key)) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}
