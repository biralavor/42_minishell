/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_env_key_rules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 04:25:59 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/11 04:31:10 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**array_lex_env_key_rules_manager(char **arr_lex, int arr_len)
{
	size_t	idx;
	size_t	pos;
	char	**new_arr;

	idx = -1;
	new_arr = (char **)ft_calloc(2, sizeof(char *) * arr_len);
	while (arr_lex[++idx])
	{
		pos = 0;
		if (env_var_key_rules_at_start(arr_lex[idx][pos]))
			pos++;
		while (env_var_key_rules_at_middle(arr_lex[idx][pos]))
			pos++;
		if (pos > 0 && arr_lex[idx][pos]
			&& !env_var_key_rules_at_middle(arr_lex[idx][pos]))
			new_arr = apply_rules_on_lex(new_arr, arr_lex[idx], pos);
		else
			new_arr = send_approved_var(new_arr, arr_lex[idx]);
	}
	new_arr = free_runner_for_env_rules_manager(arr_lex, new_arr);
	return (new_arr);
}

bool	env_var_key_rules_at_start(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (true);
	return (false);
}

bool	env_var_key_rules_at_middle(char c)
{
	if (ft_isdigit(c) || env_var_key_rules_at_start(c))
		return (true);
	return (false);
}

char	**send_approved_var(char **new_arr, char *lexeme)
{
	size_t	id;

	id = 0;
	while (new_arr[id])
		id++;
	new_arr[id] = ft_strdup(lexeme);
	return (new_arr);
}
