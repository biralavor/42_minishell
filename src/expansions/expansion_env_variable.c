/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_env_variable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/08/28 15:49:57 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expansion_env_variable_runner(char *lexeme)
{
	t_env_entry *env_table;
	char		*env_name;

	lexeme++;
	env_name = ft_strdup(lexeme);
	lexeme--;
	env_table = lookup_table(env_holder(NULL, false, false), env_name);
	if (env_table)
	{
		free(lexeme);
		free(env_name);
		lexeme = ft_strdup(env_table->value);
		return (lexeme);
	}
	return (NULL);
}
