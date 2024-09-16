/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   28.manage_subshell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:12:39 by tmalheir          #+#    #+#             */
/*   Updated: 2024/09/16 11:06:37 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	manage_subshell(t_tree *tree)
{
	char	*tmp;
	char	*new_str;

	tmp = ft_strtrim(tree->command->lexeme, "(");
	new_str = ft_strtrim(tmp, ")");
	loop_routine(new_str);
	free(tmp);
	free(new_str);
	return (0);
}