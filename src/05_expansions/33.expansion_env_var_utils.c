/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_env_var_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:02:37 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/12 10:09:03 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**send_approved_var(char **new_arr, char *lexeme)
{
	size_t	id;

	id = 0;
	while (new_arr[id])
		id++;
	new_arr[id] = ft_strdup(lexeme);
	return (new_arr);
}

char	**free_runner_for_env_rules_manager(char **arr_lex, char **new_arr)
{
	if (*new_arr)
	{
		free_array(arr_lex);
		arr_lex = NULL;
	}
	else
	{
		free_array(new_arr);
		new_arr = arr_lex;
	}
	return (new_arr);
}
