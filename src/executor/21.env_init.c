/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21.env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:58:32 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/07 13:27:06 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"



t_env_table	*create_table(int initial_size)
{
	t_env_table *table;

	table = (t_env_table *)ft_calloc(1, sizeof(t_env_table));
	if (!table)
		return (NULL);
	table->head = NULL;
	table->head = (t_env_entry **)ft_calloc(initial_size, sizeof(t_env_table *));
	if (!table->head)
	{
		free(table);
		return (NULL);
	}
	table->size = initial_size;
	return (table);
}

void	addto_env_table(t_env_table *table, const char *key, const char *value)
{
	int			hash;
	t_env_entry	*new_entry;
	float		load_factor;

	hash = hash_function(key, table->size);
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

