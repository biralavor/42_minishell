/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_env_variable.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:39:23 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/11 13:07:25 by umeneses         ###   ########.fr       */
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

char	*expansion_env_var_runner_at_middle(char *lexeme)
{
	t_env_entry	*env_table;
	char		**splited_lexeme;
	char		*env_name;
	char		*cmd;

	splited_lexeme = ft_split(lexeme, '$');
	cmd = ft_strdup(splited_lexeme[0]);
	env_name = ft_strdup(splited_lexeme[1]);
	env_table = lookup_table(env_holder(NULL, false, false), env_name);
	free(lexeme);
	free(env_name);
	if (env_table)
	{
		lexeme = ft_strjoin(cmd, env_table->value);
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

char	*copy_var_name(char *lexeme)
{
	char	**array_lex;
	char	*merged_lex;
	int		c;
	int		idx;

	idx = 0;
	c = 0;
	merged_lex = NULL;
	array_lex = NULL;
	while (lexeme[c])
	{
		if (lexeme[c] == '$')
		{
			array_lex = ft_split(lexeme, '$');
			array_lex = array_lex_env_name_convention(array_lex);
			merged_lex = merging_array_lexeme(array_lex);
			break ;
		}
		c++;
	}
	free_array(array_lex);
	free(lexeme);
	return (merged_lex);
}

char	**array_lex_env_name_convention(char **array_lex)
{
	int		idx;
	int		index;
	size_t	c;
	char	**new_array;

	idx = 0;
	index = -1;
	new_array = (char **)ft_calloc(2, sizeof(char *) * ft_array_len(array_lex));
	while (array_lex[idx])
	{
		c = 0;
		while (ft_isalpha(array_lex[idx][c]) || array_lex[idx][c] == '_')
			c++;
		if (c > 0 && !env_var_name_convention_at_middle(array_lex[idx][c]))
		{
			new_array[++index] = ft_substr(array_lex[idx], 0, c);
			if (c < ft_strlen(array_lex[idx]))
				new_array[++index] = ft_substr(array_lex[idx], c,
						ft_strlen(array_lex[idx]) - c);
		}
		idx++;
	}
	if (*new_array)
	{
		free_array(array_lex);
		return (new_array);
	}
	free_array(new_array);
	return (array_lex);
}

bool	env_var_name_convention_at_start(char c)
{
	if (ft_isalpha(c) || c == '_')
		return (true);
	return (false);
}

bool	env_var_name_convention_at_middle(char c)
{
	if (ft_isdigit(c) || ft_isalpha(c) || c == '_')
		return (true);
	return (false);
}

char	*merging_array_lexeme(char **array_lex)
{
	char	*merged_lex;
	int		idx;

	idx = 0;
	merged_lex = NULL;
	array_lex = expand_var_from_array(array_lex);
	if (array_lex[idx] && array_lex[idx + 1])
	{
		merged_lex = ft_strjoin(array_lex[idx], array_lex[idx + 1]);
		idx += 2;
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
	char		*env_name;
	int			idx;

	idx = 0;
	while (array_lex[idx])
	{
		env_name = ft_strdup(array_lex[idx]);
		env_table = lookup_table(env_holder(NULL, false, false), env_name);
		free(env_name);
		if (env_table)
		{
			free(array_lex[idx]);
			array_lex[idx] = ft_strdup(env_table->value);
		}
		idx++;
	}
	return (array_lex);
}
