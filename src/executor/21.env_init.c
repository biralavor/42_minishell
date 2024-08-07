/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21.env_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:58:32 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/07 13:26:19 by umeneses         ###   ########.fr       */
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
