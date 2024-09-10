/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_home.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:11:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/09/09 22:11:34 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expansion_tilde_detector(char *lexeme)
{
	int	idx;

	idx = 0;
	if (lexeme[idx] == '~')
		return (true);
	return (false);
}

char	*expansion_tilde_to_home(char *lexeme)
{
	char	*home_path;
	char	*new_lexeme;

	home_path = NULL;
	new_lexeme = NULL;
	if (lexeme[0] == '~')
	{
		if (lexeme[1])
			lexeme++;
		else
			lexeme[0] = '\0';
		home_path = lookup_table(env_holder(NULL, false, false), "HOME")->value;
		new_lexeme = ft_strjoin(home_path, lexeme);
	}
	return (new_lexeme);
}
