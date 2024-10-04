/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_env_var_utils_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:41:03 by tmalheir          #+#    #+#             */
/*   Updated: 2024/10/04 15:42:09 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
