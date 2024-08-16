/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22.env_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:58:03 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/16 09:46:09 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_entry	*goto_head_env_table(t_env_entry *table)
{
	while (table)
	{
		if (table->prev == NULL)
			break ;
		table = table->prev;
	}
	return (table);
}

t_env_entry	*goto_end_env_table(t_env_entry *table)
{
	while (table)
	{
		if (table->next == NULL)
			break ;
		table = table->next;
	}
	return (table);
}

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
	t_env_entry	*curr;

	tmp = table;
	curr = tmp;
	while (curr != NULL)
	{
		tmp = curr->next;
		free(curr->key);
		free(curr->value);
		curr->key = NULL;
		curr->value = NULL;
		free(curr);
		curr = tmp;
	}
}

void	free_env_array(char **envp)
{
	char	**tmp;

	tmp = envp;
	while (tmp)
	{
		free(*tmp);
		tmp++;
	}
}
