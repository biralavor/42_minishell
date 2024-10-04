/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   35.expansion_env_var_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:02:37 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/04 15:39:14 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	**apply_rules_on_lex(char **arr_lex, char *lexeme, size_t pos)
{
	size_t	id;

	id = 0;
	if (*arr_lex)
	{
		while (*arr_lex)
			id++;
	}
	else
		arr_lex[id] = ft_substr(lexeme, 0, pos);
	while (arr_lex[id])
	{
		if (pos < ft_strlen(lexeme))
		{
			arr_lex[++id] = ft_substr(lexeme, pos, ft_strlen(lexeme) - pos);
			id++;
		}
	}
	return (arr_lex);
}
