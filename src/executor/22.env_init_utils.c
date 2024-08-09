/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22.env_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:58:03 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/09 17:56:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "executor.h"

// void	resize_table(t_env_table *table)
// {
// 	int			old_size;
// 	int			idx;
// 	t_env_table	*new_table;
// 	t_env_entry	*entry;

// 	idx = 0;
// 	old_size = table->size;
// 	table->size *= 2;
// 	new_table = create_table(table->size * 2);
// 	if (!new_table)
// 		ft_putendl_fd("Memory Error: Could not resize environment table", 2);
// 	while (idx < old_size)
// 	{
// 		entry = table->head[idx];
// 		while (entry != NULL)
// 		{
// 			addto_env_table(new_table, entry->key, entry->value);
// 			entry = entry->next;
// 		}
// 		idx++;
// 	}
// 	free(table->head);
// 	table->head = new_table->head;
// 	table->size = new_table->size;
// 	free(new_table);
// }

void	goto_head_env_table(t_env_entry *table)
{
	while (table->prev)
		table = table->prev;
}

/**
 * @brief: This function uses the djb2 algorithm, which is widely
 * regarded as one of the best general-purpose hash functions.
 * It starts with a magic number (5381) and processes each character
 * of the key by shifting the current hash value left by 5 bits
 * and adding the ASCII value of the current character.
 * Finally,  * it applies the modulus operation with the table size
 * to ensure the hash value fits within the bounds of the table.
 */
unsigned long	hash_maker(const char *key, int size)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	c = *key;
	while (c != '\0')
	{
		hash = ((hash << 5) + hash) + c;
		key++;
		c = *key;
	}
	return (hash % size);
}

void	free_env_table(t_env_entry *table)
{
	t_env_entry	*tmp;

	while (table)
	{
		tmp = table;
		if (table->next)
			table = table->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = NULL;
	}
}