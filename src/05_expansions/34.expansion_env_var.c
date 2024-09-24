/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   34.expansion_env_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/24 09:25:03 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expansion_env_var_runner(char *lexeme, int type)
{
	char	**arr_lex;
	char	*merged_lex;
	int		c;

	c = 0;
	merged_lex = NULL;
	arr_lex = NULL;
	while (lexeme[c])
	{
		if (lexeme[c] == '$' && type == SINGLE_QUOTES)
			return (lexeme);
		else if (lexeme[c] == '$' && type != SINGLE_QUOTES
			&& lexeme[c + 1] && (lexeme[c + 1] != '?'))
		{
			arr_lex = ft_split(lexeme, '$');
			arr_lex = expand_var_from_array(arr_lex);
			merged_lex = merging_array_lexeme(arr_lex);
			break ;
		}
		c++;
	}
	free_array(arr_lex);
	free(lexeme);
	return (merged_lex);
}

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

char	**expand_var_from_array(char **arr_lex)
{
	t_env_entry	*env_table;
	char		*env_key;
	size_t		idx;
	size_t		c;
	char		*lex_rest;

	idx = 0;
	lex_rest = NULL;
	while (arr_lex[idx])
	{
		c = -1;
		while (arr_lex[idx][++c])
		{
			env_key = ft_substr(arr_lex[idx], 0, c + 1);
			env_table = lookup_table(env_holder(NULL, false, false), env_key);
			if (env_table)
			{
				lex_rest = ft_substr(arr_lex[idx], ft_strlen(env_key),
					ft_strlen(arr_lex[idx]) - ft_strlen(env_key));
				free(arr_lex[idx]);
				arr_lex[idx] = ft_strjoin(env_table->value, lex_rest);
				free(lex_rest);
			}
			free(env_key);
		}
		idx++;
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
	if (arr_lex[idx])
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
