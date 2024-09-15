/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04.env_init_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:58:03 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/15 16:36:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_entry	*goto_head_env_table(t_env_entry *table)
{
	while (table->prev)
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
		free(curr->key);
		free(curr->value);
		free(curr);
		curr = tmp;
	}
	*table = NULL;
}

void	free_array(char **array)
{
	char	**tmp;

	tmp = array;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(array);
}
