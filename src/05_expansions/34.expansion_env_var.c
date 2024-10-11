/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   34.expansion_env_var.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/10 21:21:13 by tmalheir         ###   ########.fr       */
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
			arr_lex = ft_split(lexeme + c, '$');
			char j = lexeme[c];
			lexeme[c] = 0;
			char *copy = ft_strdup(lexeme);
			lexeme[c] = j;
			arr_lex = expand_var_from_array(arr_lex);
			if (arr_lex)
				merged_lex = merging_array_lexeme(arr_lex);
			if (copy && merged_lex)
			{
				char *tmp = ft_strdup(merged_lex);
				free (merged_lex);
				merged_lex = ft_strjoin(copy, tmp);
				free(tmp);
			}
			free(copy);
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

static void	process_entry(char **arr_lex, size_t idx, bool *not_found)
{
	t_env_entry	*env_table;
	char		*env_key;
	size_t		c;
	char		*lex_rest;

	c = -1;
	while (arr_lex[idx][++c])
	{
		env_key = ft_substr(arr_lex[idx], 0, c + 1);
		env_table = lookup_table(env_holder(NULL, false, false), env_key);
		if (!env_table && !ft_strcmp(arr_lex[idx], env_key))
			*not_found = true;
		else if (env_table && env_table->value)
		{
			lex_rest = ft_substr(arr_lex[idx], ft_strlen(env_key),
					ft_strlen(arr_lex[idx]) - ft_strlen(env_key));
			free(arr_lex[idx]);
			arr_lex[idx] = ft_strjoin(env_table->value, lex_rest);
			free(lex_rest);
			free(env_key);
			break ;
		}
		free(env_key);
	}
}

static void	handle_not_found(char **arr_lex, size_t idx, bool not_found)
{
	if (not_found && (ft_array_len(arr_lex) == 1
			|| (idx > 0 && !arr_lex[idx - 1])))
	{
		free(arr_lex[idx]);
		arr_lex[idx] = NULL;
		exit_status_holder(0, true);
	}
}

char	**expand_var_from_array(char **arr_lex)
{
	size_t	idx;
	bool	not_found;

	idx = 0;
	not_found = false;
	while (arr_lex[idx])
	{
		process_entry(arr_lex, idx, &not_found);
		handle_not_found(arr_lex, idx, not_found);
		idx++;
	}
	return (arr_lex);
}
