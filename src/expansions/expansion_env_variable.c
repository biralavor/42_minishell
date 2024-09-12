/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_env_variable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/12 08:26:27 by umeneses         ###   ########.fr       */
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
		if (pos > 0 && !env_var_key_rules_at_middle(arr_lex[idx][pos]))
			new_arr = apply_rules_on_lex(new_arr, arr_lex[idx], pos);
	}
	if (*new_arr)
		free_array(arr_lex);
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
	while (*arr_lex)
		id++;
	while (arr_lex[id])
	{
		arr_lex[id] = ft_substr(lexeme, 0, pos);
		if (pos < ft_strlen(lexeme))
			arr_lex[++id] = ft_substr(lexeme, pos, ft_strlen(lexeme) - pos);
	}
	return (arr_lex);
}

char	*merging_array_lexeme(char **array_lex)
{
	char	*merged_lex;
	int		idx;

	idx = 0;
	merged_lex = NULL;
	array_lex = expand_var_from_array(array_lex);
	if (array_lex[idx])
	{
		merged_lex = ft_strdup(array_lex[idx]);
		idx++;
	}
	while (array_lex[idx])
	{	
		merged_lex = ft_strjoin(merged_lex, array_lex[idx]);
		idx++;
	}
	return (merged_lex);
}

char	**expand_var_from_array(char **array_lex)
{
	t_env_entry	*env_table;
	char		*env_key;
	int			idx;

	idx = 0;
	while (array_lex[idx])
	{
		env_key = ft_strdup(array_lex[idx]);
		env_table = lookup_table(env_holder(NULL, false, false), env_key);
		free(env_key);
		if (env_table)
		{
			free(array_lex[idx]);
			array_lex[idx] = ft_strdup(env_table->value);
		}
		idx++;
	}
	return (array_lex);
}
