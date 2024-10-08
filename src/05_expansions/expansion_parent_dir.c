/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_parent_dir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:22:09 by umeneses          #+#    #+#             */
/*   Updated: 2024/10/07 15:03:00 by umeneses         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	expansion_parent_dir_detector(char *lex)
{
	int	idx;

	idx = 0;
	if (lex)
	{	
		while(lex[idx])
		{
			if (lex[idx] == '.' && lex[idx + 1] == '.')
				return (true);
			idx++;
		}
	}
	return (false);
}

char	*expansion_parent_dir_runner(char *lex)
{
	int		idx;
	int		slash;
	char	*actual_path;
	char	*parent_path;

	idx = 0;
	slash = 0;
	while(lex[idx])
	{
		if (lex[idx] == '/')
			slash++;
		idx++;
	}
	idx = 0;
	actual_path = NULL;
	parent_path = NULL;
	actual_path = getcwd(actual_path, 100);
	parent_path = actual_path;
	while (actual_path[idx])
		idx++;
	while (parent_path[--idx] && slash > 0)
	{
		if (parent_path[idx] == '/')
			slash--;
		if (slash == 0)
			parent_path[idx] = '\0';
	}
	free(lex);
	exit_status_holder(0, true);
	return (parent_path);
}