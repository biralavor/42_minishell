/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.env_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:58:03 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/04 09:26:58 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_entry	*goto_head_env_table(t_env_entry *table)
{
	while (table && table->prev)
	{
		if (table->prev == NULL)
			break ;
		table = table->prev;
	}
	return (table);
}

t_env_entry	*goto_end_env_table(t_env_entry *table)
{
	while (table->next)
	{
		if (table->next == NULL)
			break ;
		table = table->next;
	}
	return (table);
}

void	free_env_table(t_env_entry **table)
{
	t_env_entry	*tmp;
	t_env_entry	*curr;

	if (NULL == *table)
		return ;
	curr = *table;
	while (curr != NULL)
	{
		tmp = curr->next;
		if (curr->key != NULL)
			free(curr->key);
		if (curr->value != NULL)
			free(curr->value);
		free(curr);
		curr = tmp;
    }
	*table = NULL;
}

void	free_array(char **array)
{
	char	**tmp;

	if (NULL == array || *array == NULL)
		return ;
	tmp = array;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(array);
}
