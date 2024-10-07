/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   33.expansion_tilde.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:11:20 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/06 23:00:21 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expansion_tilde_detector(char *lexeme)
{
	int	idx;

	idx = 0;
	if (lexeme)
		if (lexeme[idx] == '~')
			return (true);
	return (false);
}

char	*expansion_tilde_to_home(char *lexeme)
{
	char	*home_path;
	char	*new_lexeme;
	bool	tilde_not_alone;

	home_path = NULL;
	new_lexeme = NULL;
	tilde_not_alone = false;
	if (lexeme[0] == '~')
	{
		if (lexeme[1])
		{
			lexeme++;
			tilde_not_alone = true;
		}
		else
			lexeme[0] = '\0';
		home_path = lookup_table(env_holder(NULL, false, false), "HOME")->value;
		new_lexeme = ft_strjoin(home_path, lexeme);
	}
	if (tilde_not_alone)
		lexeme--;
	free(lexeme);
	return (new_lexeme);
}
