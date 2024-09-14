/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   33.expansion_env_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/14 15:39:53 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expansion_env_var_runner(char *lexeme)
{
	char	**arr_lex;
	char	*merged_lex;
	int		arr_len;
	int		c;

	c = 0;
	merged_lex = NULL;
	arr_lex = NULL;
	while (lexeme[c])
	{
		if (lexeme[c] == '$')
		{
			arr_lex = ft_split(lexeme, '$');
			arr_len = ft_array_len(arr_lex);
			arr_lex = array_lex_env_key_rules_manager(arr_lex, arr_len);
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
	int			idx;

	idx = 0;
	while (arr_lex[idx])
	{
		env_key = ft_strdup(arr_lex[idx]);
		env_table = lookup_table(env_holder(NULL, false, false), env_key);
		free(env_key);
		if (env_table)
		{
			free(arr_lex[idx]);
			arr_lex[idx] = ft_strdup(env_table->value);
		}
		idx++;
	}
	return (arr_lex);
}

char	*merging_array_lexeme(char **arr_lex)
{
	char	*merged_lex;
	int		idx;

	idx = 0;
	merged_lex = NULL;
	if (arr_lex[idx])
	{
		merged_lex = ft_strdup(arr_lex[idx]);
		idx++;
	}
	while (arr_lex[idx])
	{
		merged_lex = ft_strjoin(merged_lex, arr_lex[idx]);
		idx++;
	}
	return (merged_lex);
}
