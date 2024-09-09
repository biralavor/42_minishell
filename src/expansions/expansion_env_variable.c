/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_env_variable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 10:08:20 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expansion_env_var_runner_at_start(char *lexeme)
{
	t_env_entry	*env_table;
	char		*env_name;

	lexeme++;
	env_name = ft_strdup(lexeme);
	lexeme--;
	env_table = lookup_table(env_holder(NULL, false, false), env_name);
	free(lexeme);
	free(env_name);
	if (env_table)
	{
		lexeme = ft_strdup(env_table->value);
		exit_status_holder(0, true);
		return (lexeme);
	}
	else
	{
		lexeme = ft_strdup("");
		exit_status_holder(0, true);
		return (lexeme);
	}
}
