/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   35.expansion_env_var_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:02:37 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/11 04:31:32 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*merging_array_lexeme(char **arr_lex)
{
	char	*merged_lex;
	char	*tmp;
	int		idx;

	idx = 0;
	merged_lex = NULL;
	tmp = NULL;
	if (arr_lex && arr_lex[idx])
	{
		merged_lex = ft_strdup(arr_lex[idx]);
		idx++;
	}
	while (arr_lex[idx])
	{
		tmp = ft_strjoin(merged_lex, arr_lex[idx]);
		free(merged_lex);
		merged_lex = tmp;
		idx++;
	}
	return (merged_lex);
}
